#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"

Startwindow::Startwindow(QWidget *parent) : QWidget(parent), ui(new Ui::Startwindow) {
    ui->setupUi(this);
}

Startwindow::~Startwindow() {
    delete ui;
}

void Startwindow::updateRememberedUser(int lineIndex) {
    QFile file("accounts");
    file.open(QIODevice::ReadWrite | QIODevice::Text);

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        lines.append(in.readLine());
    }
    file.close();

    if (!lines.isEmpty()) {
        lines[0] = QString::number(lineIndex);
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const QString &line : lines) {
            out << line << "\n";
        }
        file.close();
    }
}


void Startwindow::on_createButton_clicked() {
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

    if (password.length() < 4) {
        ui->CAwarningMsgLabel->setText(" The password must contain at least 4 characters");
        return;
    }

    QFile file("accounts");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    int lineCount = 0;
    while (!in.atEnd()) {
        in.readLine();
        ++lineCount;
    }
    file.close();

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    file.open(QIODevice::Append | QIODevice::Text);

    QTextStream out(&file);
    out << username << " " << passwordHash.toHex() << "\n";
    file.close();

    if (ui->rememberMeCheckBox->isChecked()) {
        updateRememberedUser(lineCount);
    }

    MainWindow *mainWindow = new MainWindow();
    mainWindow->setUsername(username);
    mainWindow->show();

    close();
}

void Startwindow::on_loginButton_clicked() {
    QString username = ui->loginUsername->text();
    QString password = ui->loginPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        ui->LIwarningMsgLabel->setText(" All fields are required");
        return;
    }

    QFile file("accounts");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    int lineIndex = - 1;

    while (!in.atEnd()) {
        QString line = in.readLine();
        ++lineIndex;
        QStringList parts = line.split(" ");
        if (parts.size() == 2 && parts[0] == username) {
            if (parts[1] == passwordHash.toHex()) {
                file.close();

                if (ui->rememberMeCheckBox->isChecked()) {
                    updateRememberedUser(lineIndex);
                }

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

    ui->LIwarningMsgLabel->setText(" Invalid username or password");
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
