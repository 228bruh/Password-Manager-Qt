#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include "accountsmanager.h"

Startwindow::Startwindow(QWidget *parent) : QWidget(parent), ui(new Ui::Startwindow) {
    ui->setupUi(this);
}

Startwindow::~Startwindow() {
    delete ui;
}

void Startwindow::createAccount() {
    AccountsManager accountsManager;

    QString username = ui->createUsername->text();
    QString password = ui->createPassword->text();
    QString confirmPassword = ui->confirmCreatePassword->text();

    if (username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        ui->CAwarningMsgLabel->setText(" All fields are required");
        return;
    }

    if (password != confirmPassword) {
        ui->CAwarningMsgLabel->setText(" Passwords don't match");
        return;
    }

    if (username.length() < 3) {
        ui->CAwarningMsgLabel->setText(" Username must contain at least 3 characters");
        return;
    }

    if (password.length() < 4) {
        ui->CAwarningMsgLabel->setText(" Password must contain at least 4 characters");
        return;
    }

    if (accountsManager.userExists(username)) {
        ui->CAwarningMsgLabel->setText(" This username is already taken");
        return;
    }

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    accountsManager.addAccount(username, passwordHash.toHex());

    if (ui->rememberMeCheckBox->isChecked()) {
        accountsManager.updateRememberedUser(accountsManager.newIndex());
    }

    MainWindow *mainWindow = new MainWindow();
    mainWindow->setUsername(username);
    mainWindow->show();

    close();
}

void Startwindow::login() {
    QString username = ui->loginUsername->text();
    QString password = ui->loginPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        ui->LIwarningMsgLabel->setText(" All fields are required");
        return;
    }

    AccountsManager accountsManager("accounts");

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    int lineIndex = accountsManager.findUser(username, passwordHash);

    if (lineIndex != -1) {
        if (ui->rememberMeCheckBox->isChecked()) {
            accountsManager.updateRememberedUser(lineIndex);
        }

        MainWindow *mainWindow = new MainWindow();
        mainWindow->setUsername(username);
        mainWindow->show();
        close();
    } else {
        ui->LIwarningMsgLabel->setText(" Invalid username or password");
    }
}

void Startwindow::on_createButton_clicked() {
   createAccount();
}

void Startwindow::on_confirmCreatePassword_returnPressed() {
    createAccount();
}

void Startwindow::on_loginButton_clicked() {
    login();
}

void Startwindow::on_loginPassword_returnPressed() {
    login();
}

void Startwindow::on_showLIpass_stateChanged(int state) {
    if (state == Qt::Checked) {
        ui->loginPassword->setEchoMode(QLineEdit::Normal);
        ui->showLIpass->setIcon(QIcon(":/new/prefix1/resources/show.png"));
    } else {
        ui->loginPassword->setEchoMode(QLineEdit::Password);
        ui->showLIpass->setIcon(QIcon(":/new/prefix1/resources/hide.png"));
    }
}

void Startwindow::on_showCApass_stateChanged(int state) {
    if (state == Qt::Checked) {
        ui->createPassword->setEchoMode(QLineEdit::Normal);
        ui->showCApass->setIcon(QIcon(":/new/prefix1/resources/show.png"));
    } else {
        ui->createPassword->setEchoMode(QLineEdit::Password);
        ui->showCApass->setIcon(QIcon(":/new/prefix1/resources/hide.png"));
    }
}

void Startwindow::on_showCAconfpass_stateChanged(int state) {
    if (state == Qt::Checked) {
        ui->confirmCreatePassword->setEchoMode(QLineEdit::Normal);
        ui->showCAconfpass->setIcon(QIcon(":/new/prefix1/resources/show.png"));
    } else {
        ui->confirmCreatePassword->setEchoMode(QLineEdit::Password);
        ui->showCAconfpass->setIcon(QIcon(":/new/prefix1/resources/hide.png"));
    }
}
