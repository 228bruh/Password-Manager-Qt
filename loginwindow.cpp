#include "loginwindow.h"
#include "mainwindow.h"
#include "startwindow.h"
#include "ui_loginwindow.h"

Loginwindow::Loginwindow(QWidget *parent) : QWidget(parent), ui(new Ui::Loginwindow) {
    ui->setupUi(this);
}

Loginwindow::~Loginwindow() {
    delete ui;
}

void Loginwindow::setUsername() {
    QFile file("accounts");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    if (in.atEnd()) {
        file.close();
        QMessageBox::warning(this, "Error", "The accounts file is empty or corrupt");
        return;
    }

    QString firstLine = in.readLine();
    index = firstLine.toInt();

    if (index <= 0) {
        file.close();
        QMessageBox::warning(this, "Error", "Invalid index in the accounts file");
        return;
    }

    int currentLine = 1;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (currentLine == index) {
            QStringList parts = line.split(" ");
            if (parts.size() >= 1) {
                username = parts[0];
            }
            break;
        }
        ++currentLine;
    }

    file.close();

    if (!username.isEmpty()) {
        ui->welcomeLabel->setText("Welcome back, " + username);
    } else {
        ui->welcomeLabel->setText("Welcome back, User");
    }
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

void Loginwindow::on_loginButton_clicked() {
    QString password = ui->loginPassword->text();

    if (password.isEmpty()) {
        ui->LIwarningMsgLabel->setText(" Password field cannot be empty");
        return;
    }

    QFile file("accounts");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QStringList lines;

    while (!in.atEnd()) {
        lines.append(in.readLine());
    }
    file.close();

    QString line = lines.at(index);
    QStringList parts = line.split(" ");
    QString storedUsername = parts[0];
    QString storedHash = parts[1];

    if (storedHash == passwordHash.toHex()) {
        MainWindow *mainWindow = new MainWindow();
        mainWindow->setUsername(username);
        mainWindow->show();
        close();
    } else {
        ui->LIwarningMsgLabel->setText(" Incorrect password");
    }
}

void Loginwindow::on_logoutButton_clicked() {
    QFile file("accounts");
    file.open(QIODevice::ReadWrite | QIODevice::Text);

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        lines.append(in.readLine());
    }
    file.close();

    if (!lines.isEmpty()) {
        lines[0] = QString::number(0);
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const QString &line : lines) {
            out << line << "\n";
        }
        file.close();
    }

    Startwindow *startwindow = new Startwindow();
    startwindow->show();
    close();
}

