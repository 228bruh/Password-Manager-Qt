#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMenu>
#include <QInputDialog>
#include "passwordsmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;

    PasswordManager passwordManager;

    QString username;
    QString filename = username + ".json";

    QString generatedPassword;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setUsername(const QString &set_username);

    void loadTabsFromClass();

private slots:
    // my passwords
    void on_mypassButton_clicked();
    void on_addTab_button_clicked();     // tab widget
    void on_tabListWidget_customContextMenuRequested(const QPoint &pos);

    // generate password
    void on_genpassButton_clicked();
    void on_checkBox_custom_stateChanged(int state);
    void on_generateButton_clicked();
    void on_copyGenPassButton_clicked();
    void on_clearButton_clicked();


    // log out
    void on_logoutButton_clicked();

};

#endif // MAINWINDOW_H
