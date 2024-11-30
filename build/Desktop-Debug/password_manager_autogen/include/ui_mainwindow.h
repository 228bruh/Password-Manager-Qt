/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_2;
    QWidget *page_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_123;
    QCheckBox *checkBox_SC;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_abc;
    QCheckBox *checkBox_ABC;
    QCheckBox *checkBox_custom;
    QLineEdit *customCS;
    QTextEdit *textEdit;
    QFrame *line_2;
    QPushButton *generateButton;
    QFrame *line;
    QPushButton *logoutButton;
    QLabel *label;
    QPushButton *mypassButton;
    QPushButton *genpassButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1150, 780);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(1150, 780));
        MainWindow->setWindowOpacity(1.000000000000000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(240, -20, 911, 781));
        stackedWidget->setMaximumSize(QSize(16777215, 16777215));
        page = new QWidget();
        page->setObjectName("page");
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 260, 121, 51));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        horizontalLayoutWidget = new QWidget(page_2);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(60, 50, 131, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        spinBox = new QSpinBox(horizontalLayoutWidget);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimumSize(QSize(0, 30));
        spinBox->setMaximumSize(QSize(50, 16777215));
        spinBox->setWrapping(false);
        spinBox->setFrame(false);
        spinBox->setMaximum(50);
        spinBox->setValue(8);

        horizontalLayout->addWidget(spinBox);

        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 130, 301, 31));
        label_4->setFont(font);
        verticalLayoutWidget = new QWidget(page_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(60, 150, 91, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_123 = new QCheckBox(verticalLayoutWidget);
        checkBox_123->setObjectName("checkBox_123");

        verticalLayout->addWidget(checkBox_123);

        checkBox_SC = new QCheckBox(verticalLayoutWidget);
        checkBox_SC->setObjectName("checkBox_SC");

        verticalLayout->addWidget(checkBox_SC);

        verticalLayoutWidget_2 = new QWidget(page_2);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(170, 150, 91, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_abc = new QCheckBox(verticalLayoutWidget_2);
        checkBox_abc->setObjectName("checkBox_abc");

        verticalLayout_2->addWidget(checkBox_abc);

        checkBox_ABC = new QCheckBox(verticalLayoutWidget_2);
        checkBox_ABC->setObjectName("checkBox_ABC");

        verticalLayout_2->addWidget(checkBox_ABC);

        checkBox_custom = new QCheckBox(page_2);
        checkBox_custom->setObjectName("checkBox_custom");
        checkBox_custom->setGeometry(QRect(60, 260, 151, 24));
        customCS = new QLineEdit(page_2);
        customCS->setObjectName("customCS");
        customCS->setGeometry(QRect(60, 295, 171, 26));
        customCS->setMaxLength(50);
        customCS->setFrame(true);
        customCS->setDragEnabled(false);
        customCS->setReadOnly(true);
        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(60, 390, 321, 151));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        textEdit->setReadOnly(false);
        line_2 = new QFrame(page_2);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(40, 350, 361, 20));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        generateButton = new QPushButton(page_2);
        generateButton->setObjectName("generateButton");
        generateButton->setGeometry(QRect(60, 560, 121, 31));
        QFont font1;
        font1.setBold(true);
        generateButton->setFont(font1);
        stackedWidget->addWidget(page_2);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(210, 38, 20, 701));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        logoutButton = new QPushButton(centralwidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(30, 730, 160, 31));
        logoutButton->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(65, 20, 91, 91));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/resources/padlock.png")));
        label->setScaledContents(true);
        mypassButton = new QPushButton(centralwidget);
        mypassButton->setObjectName("mypassButton");
        mypassButton->setGeometry(QRect(30, 160, 160, 31));
        mypassButton->setFont(font1);
        genpassButton = new QPushButton(centralwidget);
        genpassButton->setObjectName("genpassButton");
        genpassButton->setGeometry(QRect(30, 240, 160, 31));
        genpassButton->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(mypassButton, genpassButton);
        QWidget::setTabOrder(genpassButton, logoutButton);
        QWidget::setTabOrder(logoutButton, spinBox);
        QWidget::setTabOrder(spinBox, checkBox_123);
        QWidget::setTabOrder(checkBox_123, checkBox_abc);
        QWidget::setTabOrder(checkBox_abc, checkBox_SC);
        QWidget::setTabOrder(checkBox_SC, checkBox_ABC);
        QWidget::setTabOrder(checkBox_ABC, checkBox_custom);
        QWidget::setTabOrder(checkBox_custom, customCS);
        QWidget::setTabOrder(customCS, textEdit);
        QWidget::setTabOrder(textEdit, generateButton);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        label_2->setText(QCoreApplication::translate("MainWindow", "My passwords", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Length:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Charset's:", nullptr));
        checkBox_123->setText(QCoreApplication::translate("MainWindow", "123", nullptr));
        checkBox_SC->setText(QCoreApplication::translate("MainWindow", "@$%", nullptr));
        checkBox_abc->setText(QCoreApplication::translate("MainWindow", "abc", nullptr));
        checkBox_ABC->setText(QCoreApplication::translate("MainWindow", "ABC", nullptr));
        checkBox_custom->setText(QCoreApplication::translate("MainWindow", "Custom charset", nullptr));
        generateButton->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        label->setText(QString());
        mypassButton->setText(QCoreApplication::translate("MainWindow", "My passwords", nullptr));
        genpassButton->setText(QCoreApplication::translate("MainWindow", "Generate password", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
