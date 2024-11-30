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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setUsername(const QString &set_username);

private slots:
    void on_logoutButton_clicked();

    void on_mypassButton_clicked();

    void on_genpassButton_clicked();

    void on_checkBox_custom_stateChanged(int state);

    void on_generateButton_clicked();

private:
    Ui::MainWindow *ui;
    QString username;
};

#endif // MAINWINDOW_H
