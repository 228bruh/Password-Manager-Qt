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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Startwindow
{
public:
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QLineEdit *createUsername;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QLineEdit *createPassword;
    QLabel *label_10;
    QLineEdit *confirmCreatePassword;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *label;
    QPushButton *loginButton;
    QLabel *warningMsgLabel;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLineEdit *loginPassword;
    QPushButton *createButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLineEdit *loginUsername;

    void setupUi(QWidget *Startwindow)
    {
        if (Startwindow->objectName().isEmpty())
            Startwindow->setObjectName("Startwindow");
        Startwindow->resize(790, 550);
        Startwindow->setMinimumSize(QSize(790, 550));
        Startwindow->setMaximumSize(QSize(790, 550));
        horizontalLayoutWidget_2 = new QWidget(Startwindow);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(-30, 40, 851, 51));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        horizontalLayoutWidget_2->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName("label_6");
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        verticalLayoutWidget_3 = new QWidget(Startwindow);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(480, 240, 261, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName("label_8");
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout_3->addWidget(label_8);

        createUsername = new QLineEdit(verticalLayoutWidget_3);
        createUsername->setObjectName("createUsername");
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        createUsername->setFont(font3);

        verticalLayout_3->addWidget(createUsername);

        verticalLayoutWidget_4 = new QWidget(Startwindow);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(480, 330, 261, 121));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget_4);
        label_9->setObjectName("label_9");
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout_4->addWidget(label_9);

        createPassword = new QLineEdit(verticalLayoutWidget_4);
        createPassword->setObjectName("createPassword");
        createPassword->setFont(font3);

        verticalLayout_4->addWidget(createPassword);

        label_10 = new QLabel(verticalLayoutWidget_4);
        label_10->setObjectName("label_10");
        label_10->setFont(font2);
        label_10->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout_4->addWidget(label_10);

        confirmCreatePassword = new QLineEdit(verticalLayoutWidget_4);
        confirmCreatePassword->setObjectName("confirmCreatePassword");
        confirmCreatePassword->setFont(font3);

        verticalLayout_4->addWidget(confirmCreatePassword);

        horizontalLayoutWidget = new QWidget(Startwindow);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-30, 160, 851, 80));
        QFont font4;
        font4.setPointSize(16);
        horizontalLayoutWidget->setFont(font4);
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(label_3);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(label);

        loginButton = new QPushButton(Startwindow);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(50, 480, 101, 31));
        warningMsgLabel = new QLabel(Startwindow);
        warningMsgLabel->setObjectName("warningMsgLabel");
        warningMsgLabel->setGeometry(QRect(480, 460, 261, 16));
        QFont font5;
        font5.setPointSize(8);
        warningMsgLabel->setFont(font5);
        warningMsgLabel->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);
        verticalLayoutWidget_2 = new QWidget(Startwindow);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(50, 370, 261, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout_2->addWidget(label_5);

        loginPassword = new QLineEdit(verticalLayoutWidget_2);
        loginPassword->setObjectName("loginPassword");
        loginPassword->setFont(font3);

        verticalLayout_2->addWidget(loginPassword);

        createButton = new QPushButton(Startwindow);
        createButton->setObjectName("createButton");
        createButton->setGeometry(QRect(480, 480, 101, 31));
        verticalLayoutWidget = new QWidget(Startwindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(50, 240, 261, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout->addWidget(label_4);

        loginUsername = new QLineEdit(verticalLayoutWidget);
        loginUsername->setObjectName("loginUsername");
        loginUsername->setFont(font3);

        verticalLayout->addWidget(loginUsername);


        retranslateUi(Startwindow);

        QMetaObject::connectSlotsByName(Startwindow);
    } // setupUi

    void retranslateUi(QWidget *Startwindow)
    {
        Startwindow->setWindowTitle(QCoreApplication::translate("Startwindow", "Password Manager - Log in", nullptr));
        label_6->setText(QCoreApplication::translate("Startwindow", "Welcome to Password Manager", nullptr));
        label_8->setText(QCoreApplication::translate("Startwindow", "Username", nullptr));
        createUsername->setText(QString());
        label_9->setText(QCoreApplication::translate("Startwindow", "Password", nullptr));
        label_10->setText(QCoreApplication::translate("Startwindow", "Confirm password", nullptr));
        label_3->setText(QCoreApplication::translate("Startwindow", "Log in", nullptr));
        label->setText(QCoreApplication::translate("Startwindow", "Create account", nullptr));
        loginButton->setText(QCoreApplication::translate("Startwindow", "Log in", nullptr));
        warningMsgLabel->setText(QString());
        label_5->setText(QCoreApplication::translate("Startwindow", "Password", nullptr));
        createButton->setText(QCoreApplication::translate("Startwindow", "Create", nullptr));
        label_4->setText(QCoreApplication::translate("Startwindow", "Username", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Startwindow: public Ui_Startwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
