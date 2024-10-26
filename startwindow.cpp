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

    if (password.length() < 4) {
        ui->warningMsgLabel->setText("The password must contain at least 4 characters");
        return;
    }

    if (password != confirmPassword) {
        ui->warningMsgLabel->setText("Passwords don't match");
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
            ui->warningMsgLabel->setText("Username already exists");
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

    ui->warningMsgLabel->clear();
    ui->createUsername->clear();
    ui->createPassword->clear();
    ui->confirmCreatePassword->clear();
}


void Startwindow::on_loginButton_clicked() {

}

