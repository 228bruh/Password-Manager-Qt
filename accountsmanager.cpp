#include "accountsmanager.h"

AccountsManager::AccountsManager(const QString &fileName) : fileName(fileName) {}



//////////////////////////////////////////////////////////////////////////////
// ACCOUNTS file
//////////////////////////////////////////////////////////////////////////////
void AccountsManager::initializeFile() {
    QFile file(fileName);
    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "0\n";
            file.close();
        } else {
            QMessageBox::warning(nullptr, "Error", "Failed to create file.");
        }
    } else if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for reading");
        return;
    }
}

int AccountsManager::getIndex() {
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString firstLine = in.readLine();
    file.close();

    return firstLine.toInt();
}

void AccountsManager::updateRememberedUser(int lineIndex) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for updating");
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

    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();
}

void AccountsManager::addAccount(const QString &username, const QString &hashedPassword) {
    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for appending");
        return;
    }

    QTextStream out(&file);
    out << username << " " << hashedPassword << "\n";
    file.close();

    QFile userFile(username + ".json");
    if (!userFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", QString("Failed to create file for user: %1").arg(username));
        return;
    }

    QJsonObject rootObject;
    rootObject["categories"] = QJsonObject();
    QJsonDocument doc(rootObject);
    userFile.write(doc.toJson(QJsonDocument::Indented));
    userFile.close();
}

int AccountsManager::findUser(const QString &username, const QByteArray &hashedPassword) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return -1;
    }

    QTextStream in(&file);
    int lineIndex = -1;

    while (!in.atEnd()) {
        QString line = in.readLine();
        ++lineIndex;
        QStringList parts = line.split(" ");
        if (parts.size() == 2 && parts[0] == username) {
            file.close();
            return (parts[1] == hashedPassword.toHex()) ? lineIndex : -1;
        }
    }

    file.close();
    return -1;
}

bool AccountsManager::userExists(const QString &username) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() == 2 && parts[0] == username) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

int AccountsManager::newIndex() {
    int newIndex = -1;
    QFile file("accounts");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            in.readLine();
            ++newIndex;
        }
        file.close();
    }

    return newIndex;
}

QString AccountsManager::getUsernameByIndex(int index) {
    QFile file("accounts");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QString();
    }

    QTextStream in(&file);
    int currentLine = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (currentLine == index) {
            QStringList parts = line.split(" ");
            if (!parts.isEmpty()) {
                file.close();
                return parts[0];
            }
        }
        ++currentLine;
    }

    file.close();
    return QString();
}
