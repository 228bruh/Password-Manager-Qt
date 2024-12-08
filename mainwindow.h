#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    Ui::MainWindow *ui;

    QString username;
    QString generatedPassword;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setUsername(const QString &set_username);

    void loadTabsFromJson();
    void addCategoryTab(const QString &categoryName);

private slots:
    // my passwords

    void on_mypassButton_clicked();
    void on_addTab_button_clicked();     // tab widget
    void on_removeTab_button_clicked();

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
