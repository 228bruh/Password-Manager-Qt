#include "loginwindow.h"
#include "mainwindow.h"
#include "startwindow.h"
#include "accountsmanager.h"
#include "ui_loginwindow.h"

Loginwindow::Loginwindow(QWidget *parent) : QWidget(parent), ui(new Ui::Loginwindow) {
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+Q"), this);
    connect(shortcut, &QShortcut::activated, qApp, &QApplication::quit);

    ui->setupUi(this);
}

Loginwindow::~Loginwindow() {
    delete ui;
}

void Loginwindow::setUsername() {
    AccountsManager accountsManager;

    index = accountsManager.getIndex();
    if (index < 0) {
        QMessageBox::warning(this, "Error", "Invalid or missing index in the accounts file");
        ui->welcomeLabel->setText("Welcome back, User");
        return;
    }

    QString extractedUsername = accountsManager.getUsernameByIndex(index);
    if (!extractedUsername.isEmpty()) {
        username = extractedUsername;
        ui->welcomeLabel->setText("Welcome back, " + username);
    } else {
        ui->welcomeLabel->setText("Welcome back, User");
    }
}

void Loginwindow::login() {
    AccountsManager accountsManager;

    QString password = ui->loginPassword->text();

    if (password.isEmpty()) {
        ui->LIwarningMsgLabel->setText(" Password field cannot be empty");
        return;
    }

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QString storedUsername = accountsManager.getUsernameByIndex(index);

    int foundIndex = accountsManager.findUser(storedUsername, passwordHash);
    if (foundIndex == index) {
        MainWindow *mainWindow = new MainWindow();
        mainWindow->setUsername(storedUsername);

        ///////////////////////////////
        mainWindow->loadTabsFromJson(); // replase later
        ///////////////////////////////

        mainWindow->show();
        close();
    } else {
        ui->LIwarningMsgLabel->setText(" Incorrect password");
    }
}

void Loginwindow::on_loginButton_clicked() {
    login();
}

void Loginwindow::on_loginPassword_returnPressed() {
    login();
}

void Loginwindow::on_logoutButton_clicked() {
    AccountsManager accountsManager;

    accountsManager.updateRememberedUser(0);

    Startwindow *startwindow = new Startwindow();
    startwindow->show();
    close();
}

void Loginwindow::on_showLIpass_stateChanged(int state) {
    if (state == Qt::Checked) {
        ui->loginPassword->setEchoMode(QLineEdit::Normal);
        ui->showLIpass->setIcon(QIcon(":/new/prefix1/resources/show.png"));
    } else {
        ui->loginPassword->setEchoMode(QLineEdit::Password);
        ui->showLIpass->setIcon(QIcon(":/new/prefix1/resources/hide.png"));
    }
}
