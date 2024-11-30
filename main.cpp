#include "startwindow.h"
#include "loginwindow.h"
#include "accountsmanager.h"

#include <QApplication>

#include "mainwindow.h" // temp

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    AccountsManager accountsManager;
    accountsManager.initializeFile();
///*
    Startwindow startwindow;
    Loginwindow loginwindow;

    int index = accountsManager.getIndex();
    if (index == 0) {
        startwindow.show();
    } else {
        loginwindow.setUsername();
        loginwindow.show();
    }
//*/
    //MainWindow *mainWindow = new MainWindow();
    //mainWindow->show();

    return a.exec();
}
