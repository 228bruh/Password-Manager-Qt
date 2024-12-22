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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
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
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *addPassword_button;
    QLabel *label_2;
    QLineEdit *tabName_lineEdit;
    QLabel *addTab_label;
    QLabel *label_13;
    QListWidget *tabListWidget;
    QFrame *line_3;
    QFrame *line_4;
    QLineEdit *addWebsite_lineEdit;
    QLabel *label_12;
    QLineEdit *addUsername_lineEdit;
    QLineEdit *addPassword_lineEdit;
    QCheckBox *showAddPass;
    QComboBox *add_comboBox;
    QLineEdit *search_lineEdit;
    QLabel *addPassword_label;
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
        tabWidget->setGeometry(QRect(-5, 215, 935, 565));
        QPalette palette;
        QBrush brush(QColor(42, 46, 50, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        tabWidget->setPalette(palette);
        QFont font;
        font.setBold(false);
        tabWidget->setFont(font);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setElideMode(Qt::TextElideMode::ElideNone);
        tabWidget->setDocumentMode(true);
        All_tab = new QWidget();
        All_tab->setObjectName("All_tab");
        scrollArea = new QScrollArea(All_tab);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(-16, 0, 951, 541));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 949, 539));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(All_tab, QString());
        addPassword_button = new QPushButton(page);
        addPassword_button->setObjectName("addPassword_button");
        addPassword_button->setGeometry(QRect(250, 150, 111, 31));
        QFont font1;
        font1.setBold(true);
        addPassword_button->setFont(font1);
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(416, 10, 141, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        label_2->setFont(font2);
        tabName_lineEdit = new QLineEdit(page);
        tabName_lineEdit->setObjectName("tabName_lineEdit");
        tabName_lineEdit->setGeometry(QRect(415, 50, 181, 30));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        tabName_lineEdit->setFont(font3);
        tabName_lineEdit->setMaxLength(30);
        tabName_lineEdit->setFrame(true);
        tabName_lineEdit->setDragEnabled(false);
        tabName_lineEdit->setClearButtonEnabled(true);
        addTab_label = new QLabel(page);
        addTab_label->setObjectName("addTab_label");
        addTab_label->setGeometry(QRect(417, 80, 221, 21));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(false);
        addTab_label->setFont(font4);
        label_13 = new QLabel(page);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(666, 10, 131, 31));
        label_13->setFont(font2);
        tabListWidget = new QListWidget(page);
        tabListWidget->setObjectName("tabListWidget");
        tabListWidget->setGeometry(QRect(665, 50, 211, 141));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        tabListWidget->setPalette(palette1);
        tabListWidget->setFont(font1);
        tabListWidget->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        tabListWidget->setFrameShape(QFrame::Shape::StyledPanel);
        tabListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tabListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tabListWidget->setEditTriggers(QAbstractItemView::EditTrigger::AllEditTriggers);
        tabListWidget->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        tabListWidget->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        tabListWidget->setProperty("isWrapping", QVariant(false));
        line_3 = new QFrame(page);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(390, 20, 20, 171));
        line_3->setFont(font);
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(page);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(639, 20, 20, 171));
        line_4->setFrameShape(QFrame::Shape::VLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        addWebsite_lineEdit = new QLineEdit(page);
        addWebsite_lineEdit->setObjectName("addWebsite_lineEdit");
        addWebsite_lineEdit->setGeometry(QRect(15, 50, 345, 30));
        addWebsite_lineEdit->setFont(font3);
        addWebsite_lineEdit->setMaxLength(30);
        addWebsite_lineEdit->setFrame(true);
        addWebsite_lineEdit->setDragEnabled(false);
        addWebsite_lineEdit->setClearButtonEnabled(true);
        label_12 = new QLabel(page);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(16, 10, 141, 31));
        label_12->setFont(font2);
        addUsername_lineEdit = new QLineEdit(page);
        addUsername_lineEdit->setObjectName("addUsername_lineEdit");
        addUsername_lineEdit->setGeometry(QRect(15, 100, 163, 30));
        addUsername_lineEdit->setFont(font3);
        addUsername_lineEdit->setMaxLength(30);
        addUsername_lineEdit->setFrame(true);
        addUsername_lineEdit->setDragEnabled(false);
        addUsername_lineEdit->setClearButtonEnabled(true);
        addPassword_lineEdit = new QLineEdit(page);
        addPassword_lineEdit->setObjectName("addPassword_lineEdit");
        addPassword_lineEdit->setGeometry(QRect(197, 100, 163, 30));
        addPassword_lineEdit->setFont(font3);
        addPassword_lineEdit->setMaxLength(30);
        addPassword_lineEdit->setFrame(true);
        addPassword_lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        addPassword_lineEdit->setDragEnabled(false);
        addPassword_lineEdit->setClearButtonEnabled(true);
        showAddPass = new QCheckBox(page);
        showAddPass->setObjectName("showAddPass");
        showAddPass->setGeometry(QRect(342, 107, 41, 16));
        showAddPass->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/resources/hide.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        showAddPass->setIcon(icon);
        add_comboBox = new QComboBox(page);
        add_comboBox->setObjectName("add_comboBox");
        add_comboBox->setGeometry(QRect(15, 150, 163, 30));
        add_comboBox->setEditable(true);
        add_comboBox->setFrame(true);
        search_lineEdit = new QLineEdit(page);
        search_lineEdit->setObjectName("search_lineEdit");
        search_lineEdit->setGeometry(QRect(700, 100, 141, 30));
        search_lineEdit->setMaxLength(50);
        search_lineEdit->setClearButtonEnabled(true);
        addPassword_label = new QLabel(page);
        addPassword_label->setObjectName("addPassword_label");
        addPassword_label->setGeometry(QRect(167, 180, 191, 21));
        addPassword_label->setFont(font4);
        addPassword_label->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        addPassword_label->setTextFormat(Qt::TextFormat::AutoText);
        addPassword_label->setScaledContents(false);
        addPassword_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        stackedWidget->addWidget(page);
        search_lineEdit->raise();
        showAddPass->raise();
        tabWidget->raise();
        addPassword_button->raise();
        label_2->raise();
        tabName_lineEdit->raise();
        addTab_label->raise();
        label_13->raise();
        tabListWidget->raise();
        line_3->raise();
        line_4->raise();
        addWebsite_lineEdit->raise();
        label_12->raise();
        addUsername_lineEdit->raise();
        addPassword_lineEdit->raise();
        add_comboBox->raise();
        addPassword_label->raise();
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
        spinBox->setFrame(true);
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
        customCS->setGeometry(QRect(60, 295, 191, 30));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        customCS->setPalette(palette2);
        customCS->setMaxLength(50);
        customCS->setFrame(true);
        customCS->setDragEnabled(false);
        customCS->setReadOnly(true);
        customCS->setClearButtonEnabled(true);
        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(60, 410, 321, 151));
        QPalette palette3;
        QBrush brush1(QColor(36, 40, 43, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        textEdit->setPalette(palette3);
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
        copyGenPassButton->setGeometry(QRect(310, 580, 31, 31));
        copyGenPassButton->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/resources/Copy.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        copyGenPassButton->setIcon(icon1);
        copyGenPassButton->setIconSize(QSize(20, 20));
        clearButton = new QPushButton(page_2);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(350, 580, 31, 31));
        clearButton->setFont(font1);
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("edit-clear")));
        clearButton->setIcon(icon2);
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
        QWidget::setTabOrder(addWebsite_lineEdit, addUsername_lineEdit);
        QWidget::setTabOrder(addUsername_lineEdit, addPassword_lineEdit);
        QWidget::setTabOrder(addPassword_lineEdit, add_comboBox);
        QWidget::setTabOrder(add_comboBox, addPassword_button);
        QWidget::setTabOrder(addPassword_button, tabName_lineEdit);
        QWidget::setTabOrder(tabName_lineEdit, tabListWidget);
        QWidget::setTabOrder(tabListWidget, tabWidget);
        QWidget::setTabOrder(tabWidget, scrollArea);
        QWidget::setTabOrder(scrollArea, mypassButton);
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
        QWidget::setTabOrder(generateButton, copyGenPassButton);
        QWidget::setTabOrder(copyGenPassButton, clearButton);
        QWidget::setTabOrder(clearButton, search_lineEdit);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        tabWidget->setTabText(tabWidget->indexOf(All_tab), QCoreApplication::translate("MainWindow", "All", nullptr));
        addPassword_button->setText(QCoreApplication::translate("MainWindow", "Add password", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Add category", nullptr));
        tabName_lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Category name", nullptr));
        addTab_label->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Edit categories", nullptr));
        addWebsite_lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Website", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Add password", nullptr));
        addUsername_lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "User Name*", nullptr));
        addPassword_lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password*", nullptr));
        showAddPass->setText(QString());
        add_comboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Select category", nullptr));
        search_lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search...", nullptr));
        addPassword_label->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Length:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Charset's:", nullptr));
        checkBox_123->setText(QCoreApplication::translate("MainWindow", "0 - 9", nullptr));
        checkBox_SC->setText(QCoreApplication::translate("MainWindow", "!@#$%", nullptr));
        checkBox_abc->setText(QCoreApplication::translate("MainWindow", "a - z", nullptr));
        checkBox_ABC->setText(QCoreApplication::translate("MainWindow", "A - Z", nullptr));
        checkBox_custom->setText(QCoreApplication::translate("MainWindow", "Custom charset", nullptr));
        generateButton->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        copyGenPassButton->setText(QString());
        clearButton->setText(QString());
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
