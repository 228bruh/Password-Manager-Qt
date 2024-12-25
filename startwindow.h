#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>

namespace Ui {
class Startwindow;
}

class Startwindow : public QWidget {
    Q_OBJECT

public:
    explicit Startwindow(QWidget *parent = nullptr);
    ~Startwindow();

private:
    Ui::Startwindow *ui;

    void createAccount();
    void login();
    void togglePasswordVisibility(QLineEdit *lineEdit, QCheckBox *checkBox, const QString &showIcon, const QString &hideIcon);

private slots:
    // Create account
    void on_createButton_clicked();
    void on_confirmCreatePassword_returnPressed();

    // Log in
    void on_loginButton_clicked();
    void on_loginPassword_returnPressed();

    // Passwords visibility
    void on_showLIpass_stateChanged(int state);
    void on_showCApass_stateChanged(int state);
    void on_showCAconfpass_stateChanged(int state);
};

#endif // STARTWINDOW_H
