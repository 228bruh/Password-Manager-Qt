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

void MainWindow::setUsername(const QString &set_username) {
    username = set_username;
    setWindowTitle("Password Manager - " + username);
    passwordManager.loadFromJsonFileToClass(username + ".json");
    loadTabsFromClass();
    loadPasswordsFromClass();
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

    QWidget *allTab = ui->tabWidget->widget(0);
    QScrollArea *scrollArea = allTab->findChild<QScrollArea *>("scrollArea");

    QWidget *contentWidget = scrollArea->widget();
    if (!contentWidget) {
        contentWidget = new QWidget(scrollArea);
        scrollArea->setWidget(contentWidget);
    }
    QLayout *layout = contentWidget->layout();
    if (layout) {
        delete layout;
    }

    int x = 0, y = 0;
    constexpr int WIDTH = 430;
    constexpr int HEIGHT = 180;
    constexpr int SPACING = 20;

    for (const Category &category : categories) {
        for (Password password : category.passwords) {
            QGroupBox *passwordBox = new QGroupBox(contentWidget);
            passwordBox->setGeometry(x, y, WIDTH, HEIGHT);
            passwordBox->setStyleSheet("QGroupBox { border: none; }");

            QLineEdit *websiteEdit = new QLineEdit(password.website, passwordBox);
            websiteEdit->setGeometry(20, 10, WIDTH - 20, 30);
            websiteEdit->setReadOnly(true);

            QLabel *usernameLabel = new QLabel("User Name:", passwordBox);
            usernameLabel->setGeometry(20, 50, 80, 30);
            QFont blotFont;
            QFont font_8;
            blotFont.setBold(true);
            font_8.setPointSize(8);
            usernameLabel->setFont(blotFont);
            QLineEdit *usernameEdit = new QLineEdit(password.username, passwordBox);
            usernameEdit->setGeometry(110, 50, WIDTH - 110, 30);
            usernameEdit->setReadOnly(true);

            QLabel *passwordLabel = new QLabel("Password:", passwordBox);
            passwordLabel->setGeometry(20, 90, 80, 30);
            passwordLabel->setFont(blotFont);
            QLineEdit *passwordEdit = new QLineEdit(password.password, passwordBox);
            passwordEdit->setGeometry(110, 90, WIDTH - 110, 30);
            passwordEdit->setEchoMode(QLineEdit::Password);
            passwordEdit->setReadOnly(true);

            QLabel *copyLabel = new QLabel("", passwordBox);
            copyLabel->setGeometry(200, 130, 180, 30);
            copyLabel->setFont(font_8);
            QPushButton *copyButton = new QPushButton(passwordBox);
            copyButton->setIcon(QIcon(":/new/prefix1/resources/Copy.png"));
            copyButton->setIconSize(QSize(18, 18));
            copyButton->setGeometry(WIDTH - 70, 130, 30, 30);
            connect(copyButton, &QPushButton::clicked, [password, copyLabel]() {
                QClipboard *clipboard = QGuiApplication::clipboard();
                clipboard->setText(password.password);
                copyLabel->setText("Password copied to clipboard");
                QTimer::singleShot(3000, [copyLabel]() { copyLabel->clear(); });
            });

            QPushButton *editButton = new QPushButton(passwordBox);
            editButton->setIcon(QIcon(":/new/prefix1/resources/edit.png"));
            editButton->setIconSize(QSize(24, 24));
            editButton->setGeometry(WIDTH - 30, 130, 30, 30);
            connect(editButton, &QPushButton::clicked, [this, password]() mutable {
                openEditDialog(password);
            });

            x += WIDTH + SPACING;
            if (x + WIDTH > scrollArea->width()) {
                x = 0;
                y += HEIGHT + SPACING;
            }
        }
    }

    contentWidget->setMinimumSize(scrollArea->width(), y + HEIGHT);
}

void MainWindow::openEditDialog(Password &password) {
    QDialog *editDialog = new QDialog(this);
    editDialog->setWindowTitle("Edit Password");
    editDialog->setFixedSize(450, 200);

    QLineEdit *websiteEdit = new QLineEdit(password.website, editDialog);
    websiteEdit->setGeometry(10, 10, 430, 30);

    QLabel *usernameLabel = new QLabel("User Name:", editDialog);
    usernameLabel->setGeometry(10, 50, 80, 30);
    QLineEdit *usernameEdit = new QLineEdit(password.username, editDialog);
    usernameEdit->setGeometry(100, 50, 330, 30);

    QLabel *passwordLabel = new QLabel("Password:", editDialog);
    passwordLabel->setGeometry(10, 90, 80, 30);
    QLineEdit *passwordEdit = new QLineEdit(password.password, editDialog);
    passwordEdit->setGeometry(100, 90, 330, 30);
    passwordEdit->setEchoMode(QLineEdit::Password);

    QPushButton *saveButton = new QPushButton("Save", editDialog);
    saveButton->setGeometry(350, 150, 80, 30);

    connect(saveButton, &QPushButton::clicked, [&, websiteEdit, usernameEdit, passwordEdit, editDialog]() {
        password.website = websiteEdit->text();
        password.username = usernameEdit->text();
        password.password = passwordEdit->text();
        passwordManager.sortPasswordsAlphabetically();
        editDialog->accept();
        //loadPasswordsFromClass();
    });

    editDialog->exec();
}


void MainWindow::on_tabName_lineEdit_returnPressed() {
    if (ui->tabName_lineEdit->text().isEmpty()) {
        ui->addTab_label->setText("Category must have a name");
        return;
    }

    QString tabName = ui->tabName_lineEdit->text();

    if (tabName == "All") {
        ui->addTab_label->setText("Reserved category name");
        return;
    }

    QVector<Category> &categories = passwordManager.getCategories();

    auto it = std::find_if(categories.begin(), categories.end(),
                           [&tabName](const Category &category) {
                               return category.name == tabName;
                           });

    if (it != categories.end()) {
        ui->addTab_label->setText("Category with this name already exists");
        return;
    }

    auto insertPos = std::lower_bound(categories.begin(), categories.end(), tabName,
                                      [](const Category &category, const QString &name) {
                                          return category.name < name;
                                      });
    categories.insert(insertPos, Category(tabName));

    loadTabsFromClass();

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
        }
    } else if (selectedAction == editNameAction) {
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
        return;
    }

    ui->addWebsite_lineEdit->clear();
    ui->addUsername_lineEdit->clear();
    ui->addPassword_lineEdit->clear();
    ui->addPassword_label->setText("");

    loadTabsFromClass();
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
    } else {
        ui->customCS->setReadOnly(1);
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
