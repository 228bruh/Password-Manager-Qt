#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

namespace Ui {
class Loginwindow;
}

class Loginwindow : public QWidget {
    Q_OBJECT

public:
    explicit Loginwindow(QWidget *parent = nullptr);
    ~Loginwindow();

    void setUsername();

private:
    Ui::Loginwindow *ui;

    QString username;
    int index;

    void login();

private slots:
    // Log in
    void on_loginButton_clicked();
    void on_loginPassword_returnPressed();

    // Log out
    void on_logoutButton_clicked();

    // Password visibility
    void on_showLIpass_stateChanged(int state);
};

#endif // LOGINWINDOW_H
