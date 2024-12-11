#ifndef ACCOUNTSMANAGER_H
#define ACCOUNTSMANAGER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QShortcut>
#include <QKeySequence>
#include <QClipboard>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QVector>


class AccountsManager {
private:
    QString fileName;

public:
    AccountsManager(const QString &fileName = "accounts");

    // ACCOUNTS file
    void initializeFile();

    int getIndex();

    void updateRememberedUser(int lineIndex);

    void addAccount(const QString &username, const QString &hashedPassword);

    int findUser(const QString &username, const QByteArray &hashedPassword);

    bool userExists(const QString &username);

    int newIndex();

    QString getUsernameByIndex(int index);

};

#endif // ACCOUNTSMANAGER_H
