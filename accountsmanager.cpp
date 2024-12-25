#include "accountsmanager.h"

AccountsManager::AccountsManager(const QString &fileName) : fileName(fileName) {}

// 'accounts' file
void AccountsManager::initializeFile() {
    QFile file(fileName);
    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "0\n";
        } else {
            QMessageBox::warning(nullptr, "Error", "Failed to create file.");
        }
    }
    file.close();
}

// Remember user option
int AccountsManager::getIndex() {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Failed to read file for index.");
        return -1;
    }
    QTextStream in(&file);
    bool ok;
    int index = in.readLine().toInt(&ok);
    return ok ? index : -1;
}

QString AccountsManager::getUsernameByIndex(int index) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QString();
    }
    QTextStream in(&file);
    int currentLine = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (currentLine == index) {
            QStringList parts = line.split(" ");
            return parts.value(0);
        }
        ++currentLine;
    }
    return QString();
}

int AccountsManager::newIndex() {
    int newIndex = 0;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            in.readLine();
            ++newIndex;
        }
    }
    return newIndex;
}

void AccountsManager::updateRememberedUser(int lineIndex) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Failed to update file.");
        return;
    }

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
    }
}

// Create account
void AccountsManager::addAccount(const QString &username, const QString &hashedPassword) {
    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Failed to append to file.");
        return;
    }
    QTextStream out(&file);
    out << username << " " << hashedPassword << "\n";
}

// Log in
int AccountsManager::findUser(const QString &username, const QByteArray &hashedPassword) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return -1;
    }
    QTextStream in(&file);
    int lineIndex = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() == 2 && parts[0] == username && parts[1] == hashedPassword.toHex()) {
            return lineIndex;
        }
        ++lineIndex;
    }
    return -1;
}

bool AccountsManager::userExists(const QString &username) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QStringList parts = in.readLine().split(" ");
        if (parts.size() == 2 && parts[0] == username) {
            return true;
        }
    }
    return false;
}


