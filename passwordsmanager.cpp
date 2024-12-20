#include "passwordsmanager.h"

// Password
Password::Password(const QString &website, const QString &username, const QString &password)
    : website(website), username(username), password(password) {}

Password& Password::operator=(const Password &other) {
    if (this != &other) {
        website = other.website;
        username = other.username;
        password = other.password;
    }
    return *this;
}

// Category
Category::Category(const QString &name) : name(name) {}

void Category::addPassword(const Password &password) {
    passwords.append(password);
}

// PasswordManager
void PasswordManager::loadFromJsonFileToClass(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for reading");
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    if (!jsonDoc.isObject()) {
        QMessageBox::warning(nullptr, "Error", "Invalid JSON format");
        return;
    }

    QJsonObject rootObject = jsonDoc.object();
    QJsonObject categoriesObject = rootObject.value("categories").toObject();

    categories.clear();

    for (const QString &categoryName : categoriesObject.keys()) {
        QJsonArray passwordsArray = categoriesObject.value(categoryName).toArray();
        Category category(categoryName);

        for (const QJsonValue &passwordValue : passwordsArray) {
            if (passwordValue.isObject()) {
                QJsonObject passwordObject = passwordValue.toObject();
                QString website = passwordObject.value("website").toString();
                QString username = passwordObject.value("username").toString();
                QString password = passwordObject.value("password").toString();

                category.addPassword(Password(website, username, password));
            }
        }

        categories.append(category);
    }
}

void PasswordManager::loadFromClassToJsonFile(const QString &fileName) {
    QJsonObject rootObject;
    QJsonObject categoriesObject;

    for (const Category &category : categories) {
        QJsonArray passwordsArray;

        for (const Password &password : category.passwords) {
            QJsonObject passwordObject;
            passwordObject["website"] = password.website;
            passwordObject["username"] = password.username;
            passwordObject["password"] = password.password;

            passwordsArray.append(passwordObject);
        }

        categoriesObject[category.name] = passwordsArray;
    }

    rootObject["categories"] = categoriesObject;

    QJsonDocument jsonDoc(rootObject);

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for writing");
        return;
    }

    file.write(jsonDoc.toJson(QJsonDocument::Indented));
    file.close();
}

void PasswordManager::sortPasswordsAlphabetically() {
    for (Category &category : categories) {
        std::sort(category.passwords.begin(), category.passwords.end(),
                  [](const Password &a, const Password &b) {
                      return a.website < b.website;
                  });
    }
}

QVector<Category>& PasswordManager::getCategories() {
    return categories;
}
