#include "startwindow.h"
#include "loginwindow.h"
#include "accountsmanager.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    AccountsManager accountsManager;
    accountsManager.initializeFile();

    int index = accountsManager.getIndex();
    if (index == 0) {
        Startwindow startwindow;
        startwindow.show();
    } else {
        Loginwindow loginwindow;
        loginwindow.setUsername();
        loginwindow.show();
    }

    return a.exec();
}
