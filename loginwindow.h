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

public:
    explicit Loginwindow(QWidget *parent = nullptr);
    ~Loginwindow();

    void setUsername();

    int index;
    QString username;

private slots:
    void on_showLIpass_stateChanged(int state);

    void on_loginButton_clicked();

    void on_logoutButton_clicked();

private:
    Ui::Loginwindow *ui;
};

#endif // LOGINWINDOW_H
