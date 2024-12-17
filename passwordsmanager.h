#ifndef PASSWORDSMANAGER_H
#define PASSWORDSMANAGER_H

#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class Password {
public:
    QString website;
    QString username;
    QString password;

    Password(const QString &website, const QString &username, const QString &password);
};

class Category {
public:
    QString name;
    QVector<Password> passwords;

    Category(const QString &name);
    void addPassword(const Password &password);
};

class PasswordManager {
private:
    QVector<Category> categories;

public:
    void loadFromJsonFileToClass(const QString &fileName);
    void loadFromClassToJsonFile(const QString &fileName);

    QVector<Category>& getCategories();

};

#endif // PASSWORDSMANAGER_H
