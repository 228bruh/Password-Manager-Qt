#include "mainwindow.h"
#include "startwindow.h"
#include "accountsmanager.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setUsername(const QString &set_username) {
    username = set_username;
    setWindowTitle("Password Manager - " + username);
}

// my passwords
void MainWindow::on_mypassButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}


// password generator
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

// logout
void MainWindow::on_logoutButton_clicked() {
    AccountsManager accountsManager;

    accountsManager.updateRememberedUser(0);

    Startwindow *startwindow = new Startwindow();
    startwindow->show();
    close();
}
