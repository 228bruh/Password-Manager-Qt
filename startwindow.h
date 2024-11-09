#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCryptographicHash>

namespace Ui {
class Startwindow;
}

class Startwindow : public QWidget {
    Q_OBJECT

public:
    explicit Startwindow(QWidget *parent = nullptr);
    ~Startwindow();

    void initializeFile();

    void updateRememberedUser(int lineIndex);

private slots:
    void on_createButton_clicked();

    void on_loginButton_clicked();

    void on_showLIpass_stateChanged(int state);

    void on_showCApass_stateChanged(int state);

    void on_showCAconfpass_stateChanged(int state);

private:
    Ui::Startwindow *ui;
};

#endif // STARTWINDOW_H
