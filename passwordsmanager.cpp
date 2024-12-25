#include "passwordsmanager.h"

namespace CryptoUtils {
QString secretKey;
void set_secret_key(const QString &fileName) {
    secretKey = fileName + "228bruh";
}

QByteArray getKey() {
    return QCryptographicHash::hash(secretKey.toUtf8(), QCryptographicHash::Sha256);
}

QByteArray encrypt(const QByteArray &data) {
    QByteArray result = data;
    QByteArray key = getKey();
    for (int i = 0; i < result.size(); ++i) {
        result[i] ^= key[i % key.size()];
    }
    return result;
}

QByteArray decrypt(const QByteArray &data) {
    return encrypt(data);
}
}


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

bool Password::operator==(const Password &other) const {
    return website == other.website &&
           username == other.username &&
           password == other.password;
}

// Category
Category::Category(const QString &name) : name(name) {}

void Category::addPassword(const Password &password) {
    passwords.append(password);
}

// PasswordManager
void PasswordManager::loadFromJsonFileToClass(const QString &fileName) {
    CryptoUtils::set_secret_key(fileName);

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for reading");
        return;
    }

    QByteArray encryptedData = file.readAll();
    file.close();

    QByteArray jsonData = CryptoUtils::decrypt(encryptedData);

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
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
    CryptoUtils::set_secret_key(fileName);

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
    QByteArray jsonData = jsonDoc.toJson(QJsonDocument::Indented);

    QByteArray encryptedData = CryptoUtils::encrypt(jsonData);

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for writing");
        return;
    }

    file.write(encryptedData);
    file.close();
}

void PasswordManager::sortPasswordsAlphabetically() {
    for (Category &category : categories) {
        std::sort(category.passwords.begin(), category.passwords.end(),
                  [](const Password &a, const Password &b) {
                      return a.website.toLower() < b.website.toLower();
                  });
    }
}

QVector<Category>& PasswordManager::getCategories() {
    return categories;
}
