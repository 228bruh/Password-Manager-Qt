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
}

void MainWindow::closeEvent(QCloseEvent *event) {
    passwordManager.loadFromClassToJsonFile(username + ".json");
    event->accept();
}



/////// my passwords ///////////////////////////////////////////////////////////
void MainWindow::on_mypassButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

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
}

void MainWindow::on_tabName_lineEdit_returnPressed() {
    if (ui->tabName_lineEdit->text().isEmpty()) {
        ui->addTab_label->setText("Tab must have a name");
        return;
    }

    QString tabName = ui->tabName_lineEdit->text();

    if (tabName == "All") {
        ui->addTab_label->setText("Reserved tab name");
        return;
    }

    QVector<Category> &categories = passwordManager.getCategories();

    auto it = std::find_if(categories.begin(), categories.end(),
                           [&tabName](const Category &category) {
                               return category.name == tabName;
                           });

    if (it != categories.end()) {
        ui->addTab_label->setText("Tab with this name already exists");
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
            QString("Are you sure you want to delete '%1' tab with all passwords included?").arg(tabName),
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            for (int i = 0; i < ui->tabWidget->count(); ++i) {
                QString currentTabName = ui->tabWidget->tabText(i).replace("&", "");
                if (currentTabName == tabName) {
                    ui->tabWidget->removeTab(i);
                    break;
                }
            }

            QVector<Category> &categories = passwordManager.getCategories();
            auto it = std::find_if(categories.begin(), categories.end(),
                                   [&tabName](const Category &category) { return category.name == tabName; });
            if (it != categories.end()) {
                categories.erase(it);
            }

            delete item;
        }
    } else if (selectedAction == editNameAction) {
        if (tabName == "All") {
            QMessageBox::warning(this, "Error", "Cannot rename the 'All' tab.");
            return;
        }

        bool ok;

        QInputDialog inputDialog(this);
        inputDialog.setWindowTitle("Edit Tab Name");
        inputDialog.setLabelText(QString("Enter new name for tab '%1':").arg(tabName));
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
                    QMessageBox::warning(this, "Error", "A tab with this name already exists");
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




/////// password generator //////////////////////////////////////////////////
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



/////// logout //////////////////////////////////////////////////////////////
void MainWindow::on_logoutButton_clicked() {
    AccountsManager accountsManager;

    accountsManager.updateRememberedUser(0);

    Startwindow *startwindow = new Startwindow();
    startwindow->show();
    close();
}
