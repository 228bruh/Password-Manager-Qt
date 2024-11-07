#include "mainwindow.h"
#include "startwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Startwindow startwindow;
    // MainWindow mainwindow;

    startwindow.show();
    // mainwindow.show();

    return a.exec();
}
