#include "mainwindow.h"
#include "startwindow.h"
#include "accountsmanager.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+Q"), this);
    connect(shortcut, &QShortcut::activated, qApp, &QApplication::quit);

    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setUsername(const QString &set_username, bool newUser) {
    username = set_username;
    setWindowTitle("Password Manager - " + username);

    if (!newUser) {
        passwordManager.loadFromJsonFileToClass(username + ".json");
        loadTabsFromClass();
        loadPasswordsFromClass();
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    passwordManager.loadFromClassToJsonFile(username + ".json");
    event->accept();
}



/////// my passwords ///////////////////////////////////////////////////////////
void MainWindow::loadTabsFromClass() {
    QVector<Category> &categories = passwordManager.getCategories();
    QStringList categoryNames;

    for (const Category &category : categories) {
        categoryNames.append(category.name);
    }

    while (ui->tabWidget->count() > 1) {
        ui->tabWidget->removeTab(1);
    }

    for (const QString &categoryName : categoryNames) {
        QWidget *newTab = new QWidget(ui->tabWidget);
        QVBoxLayout *layout = new QVBoxLayout(newTab);
        newTab->setLayout(layout);

        int insertIndex = ui->tabWidget->count();
        ui->tabWidget->insertTab(insertIndex, newTab, categoryName);
    }

    ui->tabListWidget->clear();
    for (const QString &categoryName : categoryNames) {
        ui->tabListWidget->addItem(categoryName);
    }

    ui->add_comboBox->clear();
    for (const QString &categoryName : categoryNames) {
        ui->add_comboBox->addItem(categoryName);
    }
}

void MainWindow::loadPasswordsFromClass() {
    QVector<Category> &categories = passwordManager.getCategories();

    for (int i = 0; i < ui->tabWidget->count(); i++) {
        QWidget *currentTab = ui->tabWidget->widget(i);
        QString tabName = ui->tabWidget->tabText(i).remove('&');

        QScrollArea *scrollArea = currentTab->findChild<QScrollArea *>("scrollArea");

        if (!scrollArea) {
            scrollArea = new QScrollArea(currentTab);
            scrollArea->setObjectName("scrollArea");
            scrollArea->setGeometry(-16, 0, 951, 541);
            scrollArea->setWidgetResizable(true);
            scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

            QWidget *contentWidget = new QWidget(scrollArea);
            scrollArea->setWidget(contentWidget);
        }

        QWidget *contentWidget = scrollArea->widget();
        if (!contentWidget) {
            contentWidget = new QWidget(scrollArea);
            scrollArea->setWidget(contentWidget);
        }

        QLayout *layout = contentWidget->layout();
        if (layout) {
            QLayoutItem *item;
            while ((item = layout->takeAt(0)) != nullptr) {
                if (item->widget()) {
                    delete item->widget();
                }
                delete item;
            }
            delete layout;
        }

        QGridLayout *gridLayout = new QGridLayout(contentWidget);
        contentWidget->setLayout(gridLayout);

        int row = 0, col = 0;

        for (Category &category : categories) {
            if (tabName == "All" || tabName == category.name) {
                for (Password &password : category.passwords) {
                    QGroupBox *passwordBox = createPasswordBox(password, contentWidget);
                    gridLayout->addWidget(passwordBox, row, col);

                    col++;
                    if (col == 2) {
                        col = 0;
                        row++;
                    }
                }
            }
        }

        contentWidget->setMinimumSize(scrollArea->width(), (row + 1) * 200);
    }
}

QGroupBox* MainWindow::createPasswordBox(Password &password, QWidget *parent) {
    // UI description
    constexpr int WIDTH = 430, HEIGHT = 180;

    QGroupBox *passwordBox = new QGroupBox(parent);
    passwordBox->setFixedSize(WIDTH, HEIGHT);
    passwordBox->setStyleSheet("QGroupBox { border: none; }");

    QLineEdit *websiteEdit = new QLineEdit(password.website, passwordBox);
    websiteEdit->setGeometry(20, 10, WIDTH - 40, 30);
    websiteEdit->setReadOnly(true);
    websiteEdit->setStyleSheet("QLineEdit { background-color: #2A2E32; }");

    QLabel *usernameLabel = new QLabel("User Name:", passwordBox);
    usernameLabel->setGeometry(21, 50, 80, 30);
    QFont boldFont;
    boldFont.setBold(true);
    usernameLabel->setFont(boldFont);

    QLineEdit *usernameEdit = new QLineEdit(password.username, passwordBox);
    usernameEdit->setGeometry(110, 50, WIDTH - 130, 30);
    usernameEdit->setReadOnly(true);
    usernameEdit->setStyleSheet("QLineEdit { background-color: #2A2E32; }");

    QLabel *passwordLabel = new QLabel("Password:", passwordBox);
    passwordLabel->setGeometry(21, 90, 80, 30);
    passwordLabel->setFont(boldFont);

    QCheckBox *ShowPassword = new QCheckBox(passwordBox);
    ShowPassword->setIcon(QIcon(":/new/prefix1/resources/hide.png"));
    ShowPassword->setGeometry(390, 98, 40, 15);

    QLineEdit *passwordEdit = new QLineEdit(password.password, passwordBox);
    passwordEdit->setGeometry(110, 90, WIDTH - 130, 30);
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setReadOnly(true);
    passwordEdit->setStyleSheet("QLineEdit { background-color: #2A2E32; }");

    QLabel *copyLabel = new QLabel("", passwordBox);
    copyLabel->setGeometry(130
                           , 130, 180, 30);
    QFont smallFont;
    smallFont.setPointSize(8);
    copyLabel->setFont(smallFont);

    QPushButton *copyButton = new QPushButton(passwordBox);
    copyButton->setIcon(QIcon(":/new/prefix1/resources/Copy.png"));
    copyButton->setIconSize(QSize(18, 18));
    copyButton->setGeometry(WIDTH - 50, 130, 30, 30);

    QPushButton *editButton = new QPushButton(passwordBox);
    editButton->setIcon(QIcon(":/new/prefix1/resources/edit.png"));
    editButton->setIconSize(QSize(24, 24));
    editButton->setGeometry(WIDTH - 100, 130, 30, 30);

    QPushButton *deleteButton = new QPushButton(passwordBox);
    deleteButton->setIcon(QIcon(":/new/prefix1/resources/delete.png"));
    deleteButton->setIconSize(QSize(20, 20));
    deleteButton->setGeometry(WIDTH - 140, 130, 30, 30);

    // SHOW PASSWORD checkBox slot
    connect(ShowPassword, &QCheckBox::stateChanged, [passwordEdit, ShowPassword](int state) {
        if (state == Qt::Checked) {
            passwordEdit->setEchoMode(QLineEdit::Normal);
            ShowPassword->setIcon(QIcon(":/new/prefix1/resources/show.png"));
        } else {
            passwordEdit->setEchoMode(QLineEdit::Password);
            ShowPassword->setIcon(QIcon(":/new/prefix1/resources/hide.png"));
        }
    });

    // COPY button slot
    connect(copyButton, &QPushButton::clicked, [password, copyLabel]() {
        QClipboard *clipboard = QGuiApplication::clipboard();
        clipboard->setText(password.password);
        copyLabel->setText("Password copied to clipboard");
        QTimer::singleShot(3000, [copyLabel]() { copyLabel->clear(); });
    });

    // EDIT button slot
    connect(editButton, &QPushButton::clicked, [this, &password]() {
        openEditDialog(password);
    });

    // DELETE button slot
    connect(deleteButton, &QPushButton::clicked, [this, &password]() {
        QMessageBox::StandardButton reply = QMessageBox::question(
            this,
            "Delete Confirmation",
            "Are you sure you want to delete this password?",
            QMessageBox::Yes | QMessageBox::No
            );

        if (reply == QMessageBox::Yes) {
            for (Category &category : passwordManager.getCategories()) {
                auto &passwords = category.passwords;
                auto it = std::find(passwords.begin(), passwords.end(), password);
                if (it != passwords.end()) {
                    passwords.erase(it);
                    break;
                }
            }

            loadPasswordsFromClass();
        }
    });

    return passwordBox;
}

void MainWindow::openEditDialog(Password &password) {
    // UI description
    QDialog *editDialog = new QDialog(this);
    editDialog->setWindowTitle("Edit Password");
    editDialog->setFixedSize(460, 195);

    QLineEdit *websiteEdit = new QLineEdit(password.website, editDialog);
    websiteEdit->setGeometry(10, 10, 420, 30);
    websiteEdit->setClearButtonEnabled(1);

    QLabel *usernameLabel = new QLabel("User Name:", editDialog);
    usernameLabel->setGeometry(11, 50, 80, 30);
    QLineEdit *usernameEdit = new QLineEdit(password.username, editDialog);
    usernameEdit->setGeometry(100, 50, 330, 30);
    usernameEdit->setClearButtonEnabled(1);

    QCheckBox *showPassword = new QCheckBox(editDialog);
    showPassword->setIcon(QIcon(":/new/prefix1/resources/hide.png"));
    showPassword->setGeometry(410, 98, 40, 15);

    QLabel *passwordLabel = new QLabel("Password:", editDialog);
    passwordLabel->setGeometry(11, 90, 80, 30);
    QLineEdit *passwordEdit = new QLineEdit(password.password, editDialog);
    passwordEdit->setGeometry(100, 90, 330, 30);
    passwordEdit->setClearButtonEnabled(1);
    passwordEdit->setEchoMode(QLineEdit::Password);



    QPushButton *saveButton = new QPushButton("Save", editDialog);
    saveButton->setGeometry(350, 150, 80, 30);

    QPushButton *cancelButton = new QPushButton("Cancel", editDialog);
    cancelButton->setGeometry(260, 150, 80, 30);

    QPushButton *resetButton = new QPushButton("Reset", editDialog);
    resetButton->setGeometry(10, 150, 50, 30);

    // SHOW PASSWORD checkBox slot
    connect(showPassword, &QCheckBox::stateChanged, [&, passwordEdit, editDialog](int state) {
        if (state == Qt::Checked) {
            passwordEdit->setEchoMode(QLineEdit::Normal);
            showPassword->setIcon(QIcon(":/new/prefix1/resources/show.png"));
        } else {
            passwordEdit->setEchoMode(QLineEdit::Password);
            showPassword->setIcon(QIcon(":/new/prefix1/resources/hide.png"));
        }
    });

    // SAVE button slot
    connect(saveButton, &QPushButton::clicked, [&, websiteEdit, usernameEdit, passwordEdit, editDialog]() {
        if (usernameEdit->text().isEmpty() || passwordEdit->text().isEmpty()) {
            QMessageBox::warning(editDialog, "Validation Error", "Username and Password fields cannot be empty.");
            return;
        }

        password.website = websiteEdit->text();
        password.username = usernameEdit->text();
        password.password = passwordEdit->text();

        passwordManager.sortPasswordsAlphabetically();
        loadPasswordsFromClass();
        editDialog->accept();
    });

    // RESET button slot
    connect(resetButton, &QPushButton::clicked, [&, websiteEdit, usernameEdit, passwordEdit, editDialog]() {
        websiteEdit->setText(password.website);
        usernameEdit->setText(password.username);
        passwordEdit->setText(password.password);
    });

    // CANCEL button slot
    connect(cancelButton, &QPushButton::clicked, editDialog, &QDialog::reject);

    editDialog->exec();
}


void MainWindow::on_tabName_lineEdit_returnPressed() {
    if (ui->tabName_lineEdit->text().isEmpty()) {
        ui->addTab_label->setText("Category must have a name");
        QTimer::singleShot(3000, this, [this]() {ui->addTab_label->clear();});
        return;
    }

    QString tabName = ui->tabName_lineEdit->text();

    if (tabName == "All") {
        ui->addTab_label->setText("Reserved category name");
        QTimer::singleShot(3000, this, [this]() {ui->addTab_label->clear();});
        return;
    }

    QVector<Category> &categories = passwordManager.getCategories();

    auto it = std::find_if(categories.begin(), categories.end(),
                           [&tabName](const Category &category) {
                               return category.name == tabName;
                           });

    if (it != categories.end()) {
        ui->addTab_label->setText("Category with this name already exists");
        QTimer::singleShot(3000, this, [this]() {ui->addTab_label->clear();});
        return;
    }

    auto insertPos = std::lower_bound(categories.begin(), categories.end(), tabName,
                                      [](const Category &category, const QString &name) {
                                          return category.name < name;
                                      });
    categories.insert(insertPos, Category(tabName));

    loadTabsFromClass();
    loadPasswordsFromClass();

    ui->addTab_label->setText("");
    ui->tabName_lineEdit->clear();
}

void MainWindow::on_tabListWidget_customContextMenuRequested(const QPoint &pos) {
    QListWidgetItem *item = ui->tabListWidget->itemAt(pos);
    if (!item) return;

    QMenu contextMenu;
    QAction *deleteAction = contextMenu.addAction("Delete");
    QAction *editNameAction = contextMenu.addAction("Edit name");
    QAction *selectedAction = contextMenu.exec(ui->tabListWidget->mapToGlobal(pos));

    QString tabName = item->text();

    // DELETE action
    if (selectedAction == deleteAction) {
        if (tabName == "All") {
            QMessageBox::warning(this, "Error", "Cannot delete the 'All' tab.");
            return;
        }

        QMessageBox::StandardButton reply = QMessageBox::question(
            this, "Confirm Deletion",
            QString("Are you sure you want to delete '%1' category with all passwords included?").arg(tabName),
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            QVector<Category> &categories = passwordManager.getCategories();

            auto it = std::find_if(categories.begin(), categories.end(),
                                   [&tabName](const Category &category) { return category.name == tabName; });
            if (it != categories.end()) {
                categories.erase(it);
            }

            loadTabsFromClass();
            loadPasswordsFromClass();
        }
    } else if (selectedAction == editNameAction) { // EDIT action
        if (tabName == "All") {
            QMessageBox::warning(this, "Error", "Cannot rename the 'All' tab.");
            return;
        }

        bool ok;

        QInputDialog inputDialog(this);
        inputDialog.setWindowTitle("Edit Category Name");
        inputDialog.setLabelText(QString("Enter new name for category '%1':").arg(tabName));
        inputDialog.setTextValue(tabName);

        ok = inputDialog.exec() == QDialog::Accepted;
        QString newTabName = inputDialog.textValue();

        if (ok && !newTabName.isEmpty()) {
            if (newTabName == "All") {
                QMessageBox::warning(this, "Error", "Cannot use the reserved name 'All'.");
                return;
            }

            for (int i = 0; i < ui->tabWidget->count(); ++i) {
                QString existingTabName = ui->tabWidget->tabText(i).replace("&", "");
                if (existingTabName == newTabName) {
                    QMessageBox::warning(this, "Error", "Category with this name already exists");
                    return;
                }
            }

            QVector<Category> &categories = passwordManager.getCategories();
            auto it = std::find_if(categories.begin(), categories.end(),
                                   [&tabName](const Category &category) { return category.name == tabName; });

            if (it != categories.end()) {
                Category updatedCategory = *it;
                updatedCategory.name = newTabName;

                categories.erase(it);
                auto newIt = std::lower_bound(categories.begin(), categories.end(), updatedCategory,
                                              [](const Category &a, const Category &b) { return a.name < b.name; });
                categories.insert(newIt, updatedCategory);
            }

            loadTabsFromClass();
            loadPasswordsFromClass();
        }
    }
}

void MainWindow::on_addPassword_button_clicked() {
    QString addedWebsite = ui->addWebsite_lineEdit->text();
    QString addedUsername = ui->addUsername_lineEdit->text();
    QString addedPassword = ui->addPassword_lineEdit->text();
    QString selectedCategory = ui->add_comboBox->currentText();

    if (selectedCategory.isEmpty() || addedUsername.isEmpty() || addedPassword.isEmpty()) {
        ui->addPassword_label->setText("Fill the required fields");
        QTimer::singleShot(3000, this, [this]() {ui->addPassword_label->clear();});
        return;
    }

    QVector<Category> &categories = passwordManager.getCategories();

    auto it = std::find_if(categories.begin(), categories.end(),
                           [&selectedCategory](const Category &category) {
                               return category.name == selectedCategory;
                           });

    if (it != categories.end()) {
        it->addPassword(Password(addedWebsite, addedUsername, addedPassword));
    } else {
        ui->addPassword_label->setText("Category not found");
        QTimer::singleShot(3000, this, [this]() {ui->addPassword_label->clear();});
        return;
    }

    ui->addWebsite_lineEdit->clear();
    ui->addUsername_lineEdit->clear();
    ui->addPassword_lineEdit->clear();
    ui->addPassword_label->setText("");

    passwordManager.sortPasswordsAlphabetically();
    loadPasswordsFromClass();
}


void MainWindow::on_mypassButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_showAddPass_stateChanged(int state) {
    if (state == Qt::Checked) {
        ui->addPassword_lineEdit->setEchoMode(QLineEdit::Normal);
        ui->showAddPass->setIcon(QIcon(":/new/prefix1/resources/show.png"));
    } else {
        ui->addPassword_lineEdit->setEchoMode(QLineEdit::Password);
        ui->showAddPass->setIcon(QIcon(":/new/prefix1/resources/hide.png"));
    }
}



/////// password generator //////////////////////////////////////////////////
void MainWindow::on_generateButton_clicked() {
    QString charSet{""};
    generatedPassword = "";

    if (ui->checkBox_custom->isChecked()) {
        charSet += ui->customCS->text();
    }
    if (ui->checkBox_123->isChecked()) {
        charSet += "1234567890";
    }
    if (ui->checkBox_SC->isChecked()) {
        charSet += "!\"#$%&'()*+,-./:;<=>?@[]^_`{|}~";
    }
    if (ui->checkBox_abc->isChecked()) {
        charSet += "abcdefghijklmnopqrstuvwxyz";
    }
    if (ui->checkBox_ABC->isChecked()) {
        charSet += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }

    if (charSet != "") {
        for (int i = 0; i < ui->spinBox->value(); i++) {
            generatedPassword += charSet.at(rand() % (int)charSet.length());
        }

        ui->textEdit->append(generatedPassword);
    }
}

void MainWindow::on_copyGenPassButton_clicked() {
    if (!generatedPassword.isEmpty()) {
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(generatedPassword);
        ui->copiedLabel->setText(" Password copied to clipboard");
        QTimer::singleShot(3000, this, [this]() {ui->copiedLabel->clear();});
    }
}

void MainWindow::on_clearButton_clicked() {
    ui->textEdit->setText("");
    generatedPassword = "";
}

void MainWindow::on_genpassButton_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_checkBox_custom_stateChanged(int state) {
    if (state == Qt::Checked) {
        ui->customCS->setReadOnly(0);
        ui->customCS->setStyleSheet("QLineEdit { background-color: #1B1E20; }");
    } else {
        ui->customCS->setReadOnly(1);
        ui->customCS->setStyleSheet("QLineEdit { background-color: #2A2E32; }");
    }
}



/////// logout //////////////////////////////////////////////////////////////
void MainWindow::on_logoutButton_clicked() {
    AccountsManager accountsManager;

    accountsManager.updateRememberedUser(0);

    Startwindow *startwindow = new Startwindow();
    startwindow->show();
    close();
}
