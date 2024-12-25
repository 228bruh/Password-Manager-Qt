#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMenu>
#include <QInputDialog>
#include <QGroupBox>
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
    QString filename;

    QString generatedPassword;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setUsername(const QString &set_username, bool newUser);

    void loadTabsFromClass();
    void loadPasswordsFromClass();
    void openEditDialog(Password &password);
    QGroupBox* createPasswordBox(Password &password, QWidget *parent);

private slots:
    // my passwords
    void on_tabName_lineEdit_returnPressed();
    void on_tabListWidget_customContextMenuRequested(const QPoint &pos);
    void on_addPassword_button_clicked();
    void on_mypassButton_clicked();
    void on_showAddPass_stateChanged(int state);

    // generate password
    void on_generateButton_clicked();
    void on_copyGenPassButton_clicked();
    void on_clearButton_clicked();
    void on_genpassButton_clicked();
    void on_checkBox_custom_stateChanged(int state);

    // log out
    void on_logoutButton_clicked();

};

#endif // MAINWINDOW_H
