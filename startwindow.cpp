#include "startwindow.h"
#include "ui_startwindow.h"
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

    QMessageBox::information(this, "Success", "Account successfully created!");

    ui->CAwarningMsgLabel->clear();
    ui->createUsername->clear();
    ui->createPassword->clear();
    ui->confirmCreatePassword->clear();
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
                QMessageBox::information(this, "Success", "Successfully logged in!");
                file.close();

                ui->LIwarningMsgLabel->clear();
                ui->loginUsername->clear();
                ui->loginPassword->clear();

                return;
            } else {
                break;
            }
        }
    }
    file.close();

    ui->LIwarningMsgLabel->setText("Invalid username or password");
}


