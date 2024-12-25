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

    // 'accounts' file
    void initializeFile();

    // Remember user option
    int getIndex();
    QString getUsernameByIndex(int index);
    int newIndex();
    void updateRememberedUser(int lineIndex);

    // Create account
    void addAccount(const QString &username, const QString &hashedPassword);

    // Log in
    int findUser(const QString &username, const QByteArray &hashedPassword);
    bool userExists(const QString &username);
};

#endif // ACCOUNTSMANAGER_H
