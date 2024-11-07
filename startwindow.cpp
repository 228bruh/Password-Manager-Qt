#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCryptographicHash>

Startwindow::Startwindow(QWidget *parent) : QWidget(parent), ui(new Ui::Startwindow) {
    ui->setupUi(this);
}

Startwindow::~Startwindow() {
    delete ui;
}

void Startwindow::on_createButton_clicked() {
    QString username = ui->createUsername->text();
    QString password = ui->createPassword->text();
    QString confirmPassword = ui->confirmCreatePassword->text();

    if (username.length() == 0 || password.length() == 0 || confirmPassword.length() == 0) {
        ui->CAwarningMsgLabel->setText("All fields are required");
        return;
    }

    if (password != confirmPassword) {
        ui->CAwarningMsgLabel->setText("Passwords don't match");
        return;
    }

    if (password.length() < 4) {
        ui->CAwarningMsgLabel->setText("The password must contain at least 4 characters");
        return;
    }

    QFile file("accounts");

    if (!file.exists()) {
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, "Error", "Failed to create file.");
            return;
        }
        file.close();
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Failed to open file for reading");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() > 0 && parts[0] == username) {
            ui->CAwarningMsgLabel->setText("Username already exists");
            file.close();
            return;
        }
    }
    file.close();

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Failed to open file for writing");
        return;
    }

    QTextStream out(&file);
    out << username << " " << passwordHash.toHex() << "\n";
    file.close();

    MainWindow *mainWindow = new MainWindow();
    mainWindow->setUsername(username);
    mainWindow->show();

    close();
}

void Startwindow::on_loginButton_clicked() {
    QString username = ui->loginUsername->text();
    QString password = ui->loginPassword->text();

    if (username.length() == 0 || password.length() == 0) {
        ui->LIwarningMsgLabel->setText("All fields are required");
        return;
    }

    QFile file("accounts");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Failed to open file for reading");
        return;
    }

    QTextStream in(&file);
    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() == 2 && parts[0] == username) {
            if (parts[1] == passwordHash.toHex()) {
                file.close();

                MainWindow *mainWindow = new MainWindow();
                mainWindow->setUsername(username);
                mainWindow->show();

                close();
                return;
            } else {
                break;
            }
        }
    }
    file.close();

    ui->LIwarningMsgLabel->setText("Invalid username or password");
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

