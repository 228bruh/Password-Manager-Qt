#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include "accountsmanager.h"

Startwindow::Startwindow(QWidget *parent) : QWidget(parent), ui(new Ui::Startwindow) {
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+Q"), this);
    connect(shortcut, &QShortcut::activated, qApp, &QApplication::quit);

    ui->setupUi(this);
}

Startwindow::~Startwindow() {
    delete ui;
}

void Startwindow::createAccount() {
    AccountsManager accountsManager;

    QString username = ui->createUsername->text().trimmed();
    QString password = ui->createPassword->text();
    QString confirmPassword = ui->confirmCreatePassword->text();

    if (username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        ui->CAwarningMsgLabel->setText("All fields are required");
        return;
    }

    if (username.contains(" ")) {
        ui->CAwarningMsgLabel->setText("Spaces are not allowed in Username");
        return;
    }

    if (password != confirmPassword) {
        ui->CAwarningMsgLabel->setText("Passwords don't match");
        return;
    }

    if (username.length() < 3) {
        ui->CAwarningMsgLabel->setText("Username must contain at least 3 characters");
        return;
    }

    if (password.length() < 4) {
        ui->CAwarningMsgLabel->setText("Password must contain at least 4 characters");
        return;
    }

    if (accountsManager.userExists(username)) {
        ui->CAwarningMsgLabel->setText("This username is already taken");
        return;
    }

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    accountsManager.addAccount(username, passwordHash.toHex());

    if (ui->rememberMeCheckBox->isChecked()) {
        accountsManager.updateRememberedUser(accountsManager.newIndex());
    }

    MainWindow *mainWindow = new MainWindow();
    mainWindow->setUsername(username, 1);
    mainWindow->show();
    close();
}

void Startwindow::login() {
    QString username = ui->loginUsername->text().trimmed();
    QString password = ui->loginPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        ui->LIwarningMsgLabel->setText("All fields are required");
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
        mainWindow->setUsername(username, 0);
        mainWindow->show();
        close();
    } else {
        ui->LIwarningMsgLabel->setText("Invalid username or password");
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
    togglePasswordVisibility(ui->loginPassword, ui->showLIpass, ":/new/prefix1/resources/show.png", ":/new/prefix1/resources/hide.png");
}

void Startwindow::on_showCApass_stateChanged(int state) {
    togglePasswordVisibility(ui->createPassword, ui->showCApass, ":/new/prefix1/resources/show.png", ":/new/prefix1/resources/hide.png");
}

void Startwindow::on_showCAconfpass_stateChanged(int state) {
    togglePasswordVisibility(ui->confirmCreatePassword, ui->showCAconfpass, ":/new/prefix1/resources/show.png", ":/new/prefix1/resources/hide.png");
}

void Startwindow::togglePasswordVisibility(QLineEdit *lineEdit, QCheckBox *checkBox, const QString &showIcon, const QString &hideIcon) {
    if (checkBox->isChecked()) {
        lineEdit->setEchoMode(QLineEdit::Normal);
        checkBox->setIcon(QIcon(showIcon));
    } else {
        lineEdit->setEchoMode(QLineEdit::Password);
        checkBox->setIcon(QIcon(hideIcon));
    }
}
