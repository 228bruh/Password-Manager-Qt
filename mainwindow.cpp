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
}



//////////////////////////////////////////////////////////////////////////////
// my passwords
//////////////////////////////////////////////////////////////////////////////
void MainWindow::loadTabsFromJson() {
    QString fileName = username + ".json";

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open .json file for reading");
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    file.close();

    if (!doc.isObject()) {
        QMessageBox::warning(nullptr, "Error", "Error in .json file");
        return;
    }

    QJsonObject rootObject = doc.object();
    QJsonObject categories = rootObject["categories"].toObject();

    for (const QString &categoryName : categories.keys()) {
        addCategoryTab(categoryName);
    }
}

void MainWindow::addCategoryTab(const QString &categoryName) {
    if (categoryName == "All" || categoryName == "Edit") {
        return;
    }

    QWidget *newTab = new QWidget(ui->tabWidget);
    QVBoxLayout *layout = new QVBoxLayout(newTab);
    newTab->setLayout(layout);

    int insertIndex = ui->tabWidget->count() - 1;
    ui->tabWidget->insertTab(insertIndex, newTab, categoryName);
}
//////////////////////////////////////////////////////////////////////////////



void MainWindow::on_mypassButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_addTab_button_clicked() {
    if (ui->tabName_lineEdit->text().isEmpty()) {
        ui->addTab_label->setText(" Tab must have a name");
        return;
    }

    QString tabName = ui->tabName_lineEdit->text();

    if (tabName == "All" || tabName == "Edit") {
        ui->addTab_label->setText(" Reserved tab name");
        return;
    }

    QWidget *newTab = new QWidget(ui->tabWidget);
    QVBoxLayout *layout = new QVBoxLayout(newTab);
    newTab->setLayout(layout);

    int insertIndex = ui->tabWidget->count() - 1;
    ui->tabWidget->insertTab(insertIndex, newTab, tabName);

    QString fileName = username + ".json";
    QFile file(fileName);

    QJsonObject rootObject;
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        rootObject = doc.object();
        file.close();
    }

    QJsonObject categories = rootObject["categories"].toObject();
    if (!categories.contains(tabName)) {
        categories[tabName] = QJsonArray();
        rootObject["categories"] = categories;

        if (file.open(QIODevice::WriteOnly)) {
            QJsonDocument doc(rootObject);
            file.write(doc.toJson(QJsonDocument::Indented));
            file.close();
        }
    }

    ui->addTab_label->setText("");
    ui->tabName_lineEdit->clear();
}

void MainWindow::on_removeTab_button_clicked() {
    ui->tabWidget->removeTab(ui->tabWidget->count() - 2);
}




//////////////////////////////////////////////////////////////////////////////
// password generator
//////////////////////////////////////////////////////////////////////////////
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




//////////////////////////////////////////////////////////////////////////////
// logout
//////////////////////////////////////////////////////////////////////////////
void MainWindow::on_logoutButton_clicked() {
    AccountsManager accountsManager;

    accountsManager.updateRememberedUser(0);

    Startwindow *startwindow = new Startwindow();
    startwindow->show();
    close();
}

