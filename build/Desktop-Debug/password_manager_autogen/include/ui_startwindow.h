/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Startwindow
{
public:

    void setupUi(QWidget *Startwindow)
    {
        if (Startwindow->objectName().isEmpty())
            Startwindow->setObjectName("Startwindow");
        Startwindow->resize(850, 600);
        Startwindow->setMinimumSize(QSize(850, 600));
        Startwindow->setMaximumSize(QSize(850, 600));

        retranslateUi(Startwindow);

        QMetaObject::connectSlotsByName(Startwindow);
    } // setupUi

    void retranslateUi(QWidget *Startwindow)
    {
        Startwindow->setWindowTitle(QCoreApplication::translate("Startwindow", "Password Manager - Log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Startwindow: public Ui_Startwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
