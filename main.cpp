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
        Startwindow *startwindow = new Startwindow();
        startwindow->show();
    } else {
        Loginwindow *loginwindow = new Loginwindow();
        loginwindow->setUsername();
        loginwindow->show();
    }

    return a.exec();
}
