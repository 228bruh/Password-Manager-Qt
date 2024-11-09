#include "startwindow.h"
#include "loginwindow.h"

#include <QApplication>


void initializeFile(); // убрать в .h
int getIndex();


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    initializeFile();

    Startwindow startwindow;
    Loginwindow loginwindow;

    int index = getIndex();
    if(index == 0) {
        startwindow.show();
    } else {
        loginwindow.setUsername();
        loginwindow.show();
    }

    return a.exec();
}

void initializeFile() {
    QFile file("accounts");
    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "0\n";
            file.close();
        } else {
            QMessageBox::warning(nullptr, "Error", "Failed to create file.");
        }
    } else if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open file for reading");
        return;
    }
}

int getIndex() {
    QFile file("accounts");
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString firstLine = in.readLine();
    int index = firstLine.toInt();

    return index;
}
