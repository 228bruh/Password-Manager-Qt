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
void PasswordManager::loadFromFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for reading");
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    file.close();

    if (!doc.isObject()) {
        QMessageBox::warning(nullptr, "Error", "Invalid JSON structure");
        return;
    }

    QJsonObject rootObject = doc.object();
    QJsonObject categoriesObject = rootObject["categories"].toObject();

    for (const QString &categoryName : categoriesObject.keys()) {
        QJsonArray passwordsArray = categoriesObject[categoryName].toArray();
        Category category(categoryName);

        for (const QJsonValue &passwordValue : passwordsArray) {
            QJsonObject passwordObject = passwordValue.toObject();
            QString website = passwordObject["website"].toString();
            QString username = passwordObject["username"].toString();
            QString password = passwordObject["password"].toString();

            category.addPassword(Password(website, username, password));
        }

        categories.append(category);
    }
}

void PasswordManager::saveToFile(const QString &fileName) const {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for writing");
        return;
    }

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
    QJsonDocument doc(rootObject);
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
}

QVector<Category>& PasswordManager::getCategories() {
    return categories;
}

Category* PasswordManager::findCategory(const QString &name) {
    for (Category &category : categories) {
        if (category.name == name) {
            return &category;
        }
    }
    return nullptr;
}

void PasswordManager::addCategory(const QString &name) {
    if (findCategory(name) == nullptr) {
        categories.append(Category(name));
    }
}

void PasswordManager::removeCategory(const QString &name) {
    auto it = std::remove_if(categories.begin(), categories.end(), [&](const Category &category) {
        return category.name == name;
    });
    if (it != categories.end()) {
        categories.erase(it, categories.end());
    }
}

