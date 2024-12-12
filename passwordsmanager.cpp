#include "passwordsmanager.h"

// Password
Password::Password(const QString &website, const QString &username, const QString &password)
    : website(website), username(username), password(password) {}

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


QVector<Category>& PasswordManager::getCategories() {
    return categories;
}








/*

bool PasswordManager::readJsonFile(QJsonObject &rootObject, const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for reading");
        return false;
    }
    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) {
        QMessageBox::warning(nullptr, "Error", "Invalid JSON structure");
        return false;
    }

    rootObject = doc.object();
    return true;
}

bool PasswordManager::writeJsonFile(const QJsonObject &rootObject) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for writing");
        return false;
    }

    QJsonDocument doc(rootObject);
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
    return true;
}

void PasswordManager::loadFromFile() {
    QJsonObject rootObject;
    if (!readJsonFile(rootObject)) return;

    QJsonObject categoriesObject = rootObject["categories"].toObject();

    for (const QString &categoryName : categoriesObject.keys()) {
        QJsonArray passwordsArray = categoriesObject[categoryName].toArray();
        Category category(categoryName);

        for (const QJsonValue &passwordValue : passwordsArray) {
            QJsonObject passwordObject = passwordValue.toObject();
            category.addPassword(Password(
                passwordObject["website"].toString(),
                passwordObject["username"].toString(),
                passwordObject["password"].toString()
                ));
        }
        categories.append(category);
    }
}

void PasswordManager::saveToFile() const {
    QJsonObject rootObject;
    QJsonObject categoriesObject;

    for (const Category &category : categories) {
        QJsonArray passwordsArray;
        for (const Password &password : category.passwords) {
            QJsonObject passwordObject{
                {"website", password.website},
                {"username", password.username},
                {"password", password.password}
            };
            passwordsArray.append(passwordObject);
        }
        categoriesObject[category.name] = passwordsArray;
    }

    rootObject["categories"] = categoriesObject;
    writeJsonFile(rootObject);
}

void PasswordManager::addCategory(const QString &name) {
    if (findCategory(name) == nullptr) {
        categories.append(Category(name));
    }
}

void PasswordManager::removeCategory(const QString &name) {
    categories.erase(std::remove_if(categories.begin(), categories.end(),
                                    [&](const Category &category) { return category.name == name; }),
                     categories.end());
}

Category* PasswordManager::findCategory(const QString &name) {
    auto it = std::find_if(categories.begin(), categories.end(),
                           [&](const Category &category) { return category.name == name; });
    return it != categories.end() ? &(*it) : nullptr;
}

QVector<Category>& PasswordManager::getCategories() {
    return categories;
}


*/
