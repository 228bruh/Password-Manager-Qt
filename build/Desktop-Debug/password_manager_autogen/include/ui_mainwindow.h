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
#include <QtWidgets/QTabWidget>
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
    QTabWidget *tabWidget;
    QWidget *All_tab;
    QWidget *Edit_tab;
    QPushButton *addTab_button;
    QLabel *label_2;
    QLineEdit *tabName_lineEdit;
    QLabel *label_12;
    QFrame *line_3;
    QLabel *label_13;
    QLabel *addTab_label;
    QPushButton *removeTab_button;
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
    QPushButton *copyGenPassButton;
    QPushButton *clearButton;
    QLabel *copiedLabel;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
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
        MainWindow->setMinimumSize(QSize(1150, 780));
        MainWindow->setMaximumSize(QSize(1150, 780));
        MainWindow->setWindowOpacity(1.000000000000000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(220, 0, 931, 781));
        stackedWidget->setMaximumSize(QSize(16777215, 16777215));
        page = new QWidget();
        page->setObjectName("page");
        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(36, 115, 901, 671));
        QFont font;
        font.setBold(false);
        tabWidget->setFont(font);
        All_tab = new QWidget();
        All_tab->setObjectName("All_tab");
        tabWidget->addTab(All_tab, QString());
        Edit_tab = new QWidget();
        Edit_tab->setObjectName("Edit_tab");
        addTab_button = new QPushButton(Edit_tab);
        addTab_button->setObjectName("addTab_button");
        addTab_button->setGeometry(QRect(40, 170, 161, 31));
        QFont font1;
        font1.setBold(true);
        addTab_button->setFont(font1);
        label_2 = new QLabel(Edit_tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 40, 141, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        label_2->setFont(font2);
        tabName_lineEdit = new QLineEdit(Edit_tab);
        tabName_lineEdit->setObjectName("tabName_lineEdit");
        tabName_lineEdit->setGeometry(QRect(40, 120, 191, 26));
        label_12 = new QLabel(Edit_tab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 100, 121, 18));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        label_12->setFont(font3);
        line_3 = new QFrame(Edit_tab);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(435, 30, 20, 575));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        label_13 = new QLabel(Edit_tab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(485, 40, 141, 31));
        label_13->setFont(font2);
        addTab_label = new QLabel(Edit_tab);
        addTab_label->setObjectName("addTab_label");
        addTab_label->setGeometry(QRect(40, 150, 311, 21));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(false);
        addTab_label->setFont(font4);
        removeTab_button = new QPushButton(Edit_tab);
        removeTab_button->setObjectName("removeTab_button");
        removeTab_button->setGeometry(QRect(500, 160, 161, 31));
        removeTab_button->setFont(font1);
        tabWidget->addTab(Edit_tab, QString());
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
        label_3->setFont(font2);

        horizontalLayout->addWidget(label_3);

        spinBox = new QSpinBox(horizontalLayoutWidget);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimumSize(QSize(0, 30));
        spinBox->setMaximumSize(QSize(50, 16777215));
        spinBox->setWrapping(false);
        spinBox->setFrame(false);
        spinBox->setMinimum(4);
        spinBox->setMaximum(50);
        spinBox->setValue(12);

        horizontalLayout->addWidget(spinBox);

        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 130, 301, 31));
        label_4->setFont(font2);
        verticalLayoutWidget = new QWidget(page_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(60, 150, 91, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_123 = new QCheckBox(verticalLayoutWidget);
        checkBox_123->setObjectName("checkBox_123");
        checkBox_123->setChecked(true);

        verticalLayout->addWidget(checkBox_123);

        checkBox_SC = new QCheckBox(verticalLayoutWidget);
        checkBox_SC->setObjectName("checkBox_SC");
        checkBox_SC->setChecked(true);

        verticalLayout->addWidget(checkBox_SC);

        verticalLayoutWidget_2 = new QWidget(page_2);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(170, 150, 91, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_abc = new QCheckBox(verticalLayoutWidget_2);
        checkBox_abc->setObjectName("checkBox_abc");
        checkBox_abc->setChecked(true);

        verticalLayout_2->addWidget(checkBox_abc);

        checkBox_ABC = new QCheckBox(verticalLayoutWidget_2);
        checkBox_ABC->setObjectName("checkBox_ABC");
        checkBox_ABC->setChecked(true);

        verticalLayout_2->addWidget(checkBox_ABC);

        checkBox_custom = new QCheckBox(page_2);
        checkBox_custom->setObjectName("checkBox_custom");
        checkBox_custom->setGeometry(QRect(60, 260, 151, 24));
        customCS = new QLineEdit(page_2);
        customCS->setObjectName("customCS");
        customCS->setGeometry(QRect(60, 295, 191, 26));
        customCS->setMaxLength(50);
        customCS->setFrame(true);
        customCS->setDragEnabled(false);
        customCS->setReadOnly(true);
        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(60, 410, 321, 151));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        textEdit->setReadOnly(true);
        line_2 = new QFrame(page_2);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(60, 360, 351, 20));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        generateButton = new QPushButton(page_2);
        generateButton->setObjectName("generateButton");
        generateButton->setGeometry(QRect(60, 580, 161, 31));
        generateButton->setFont(font1);
        copyGenPassButton = new QPushButton(page_2);
        copyGenPassButton->setObjectName("copyGenPassButton");
        copyGenPassButton->setGeometry(QRect(270, 580, 51, 31));
        copyGenPassButton->setFont(font1);
        clearButton = new QPushButton(page_2);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(330, 580, 51, 31));
        clearButton->setFont(font1);
        copiedLabel = new QLabel(page_2);
        copiedLabel->setObjectName("copiedLabel");
        copiedLabel->setGeometry(QRect(60, 620, 311, 21));
        QFont font5;
        font5.setPointSize(8);
        copiedLabel->setFont(font5);
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(470, 45, 401, 21));
        label_5->setTextFormat(Qt::TextFormat::RichText);
        label_6 = new QLabel(page_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(470, 65, 401, 21));
        label_6->setTextFormat(Qt::TextFormat::RichText);
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(470, 140, 401, 21));
        label_7->setTextFormat(Qt::TextFormat::RichText);
        label_8 = new QLabel(page_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(470, 200, 401, 21));
        label_8->setTextFormat(Qt::TextFormat::RichText);
        label_9 = new QLabel(page_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(470, 180, 401, 21));
        label_9->setTextFormat(Qt::TextFormat::RichText);
        label_10 = new QLabel(page_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(470, 160, 401, 21));
        label_10->setTextFormat(Qt::TextFormat::RichText);
        label_11 = new QLabel(page_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(470, 220, 401, 21));
        label_11->setTextFormat(Qt::TextFormat::RichText);
        stackedWidget->addWidget(page_2);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(210, 28, 20, 721));
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
        QWidget::setTabOrder(generateButton, copyGenPassButton);
        QWidget::setTabOrder(copyGenPassButton, clearButton);
        QWidget::setTabOrder(clearButton, spinBox);
        QWidget::setTabOrder(spinBox, checkBox_123);
        QWidget::setTabOrder(checkBox_123, checkBox_abc);
        QWidget::setTabOrder(checkBox_abc, checkBox_SC);
        QWidget::setTabOrder(checkBox_SC, checkBox_ABC);
        QWidget::setTabOrder(checkBox_ABC, checkBox_custom);
        QWidget::setTabOrder(checkBox_custom, customCS);
        QWidget::setTabOrder(customCS, textEdit);
        QWidget::setTabOrder(textEdit, mypassButton);
        QWidget::setTabOrder(mypassButton, genpassButton);
        QWidget::setTabOrder(genpassButton, logoutButton);
        QWidget::setTabOrder(logoutButton, tabWidget);
        QWidget::setTabOrder(tabWidget, tabName_lineEdit);
        QWidget::setTabOrder(tabName_lineEdit, addTab_button);
        QWidget::setTabOrder(addTab_button, removeTab_button);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        tabWidget->setTabText(tabWidget->indexOf(All_tab), QCoreApplication::translate("MainWindow", "All", nullptr));
        addTab_button->setText(QCoreApplication::translate("MainWindow", "Add tab", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Add new tab", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", " Tab name", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Edit tabs", nullptr));
        addTab_label->setText(QString());
        removeTab_button->setText(QCoreApplication::translate("MainWindow", "Remove last tab", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Edit_tab), QCoreApplication::translate("MainWindow", "Edit", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Length:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Charset's:", nullptr));
        checkBox_123->setText(QCoreApplication::translate("MainWindow", "0 - 9", nullptr));
        checkBox_SC->setText(QCoreApplication::translate("MainWindow", "!@#$%", nullptr));
        checkBox_abc->setText(QCoreApplication::translate("MainWindow", "a - z", nullptr));
        checkBox_ABC->setText(QCoreApplication::translate("MainWindow", "A - Z", nullptr));
        checkBox_custom->setText(QCoreApplication::translate("MainWindow", "Custom charset", nullptr));
        generateButton->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        copyGenPassButton->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        copiedLabel->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Use passwords that are <span style=\" font-weight:700;\">at least 12 characters long.</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>For enhanced security, consider using <span style=\" font-weight:700;\">16 or more characters</span>.</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>A strong password should include a mix of:</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p> - Uppercase letters (A - Z)</p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>- Lowercase letters (a - z)</p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>- Numbers (0 - 9)</p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>- Special characters (!@#$%^&amp;*)</p></body></html>", nullptr));
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
