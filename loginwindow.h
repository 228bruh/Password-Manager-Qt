#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class Loginwindow;
}

class Loginwindow : public QWidget {
    Q_OBJECT

private:
    QString username;
    int index;

public:
    explicit Loginwindow(QWidget *parent = nullptr);
    ~Loginwindow();

    void setUsername();

    void login();

private slots:
    void on_loginButton_clicked();
    void on_loginPassword_returnPressed();

    void on_logoutButton_clicked();

    void on_showLIpass_stateChanged(int state);

private:
    Ui::Loginwindow *ui;
};

#endif // LOGINWINDOW_H
