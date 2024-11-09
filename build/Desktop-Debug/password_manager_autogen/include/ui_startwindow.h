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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
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
    QLabel *CAwarningMsgLabel;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLineEdit *loginPassword;
    QPushButton *createButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLineEdit *loginUsername;
    QLabel *LIwarningMsgLabel;
    QLabel *label_6;
    QLabel *label_2;
    QFrame *line;
    QLabel *label_7;
    QCheckBox *rememberMeCheckBox;
    QFrame *line_2;
    QCheckBox *showCApass;
    QCheckBox *showCAconfpass;
    QCheckBox *showLIpass;

    void setupUi(QWidget *Startwindow)
    {
        if (Startwindow->objectName().isEmpty())
            Startwindow->setObjectName("Startwindow");
        Startwindow->resize(790, 600);
        Startwindow->setMinimumSize(QSize(790, 550));
        Startwindow->setMaximumSize(QSize(790, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/resources/password-manager.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Startwindow->setWindowIcon(icon);
        verticalLayoutWidget_3 = new QWidget(Startwindow);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(480, 240, 261, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName("label_8");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout_3->addWidget(label_8);

        createUsername = new QLineEdit(verticalLayoutWidget_3);
        createUsername->setObjectName("createUsername");
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        createUsername->setFont(font1);

        verticalLayout_3->addWidget(createUsername);

        verticalLayoutWidget_4 = new QWidget(Startwindow);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(480, 330, 261, 121));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget_4);
        label_9->setObjectName("label_9");
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout_4->addWidget(label_9);

        createPassword = new QLineEdit(verticalLayoutWidget_4);
        createPassword->setObjectName("createPassword");
        createPassword->setFont(font1);
        createPassword->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_4->addWidget(createPassword);

        label_10 = new QLabel(verticalLayoutWidget_4);
        label_10->setObjectName("label_10");
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout_4->addWidget(label_10);

        confirmCreatePassword = new QLineEdit(verticalLayoutWidget_4);
        confirmCreatePassword->setObjectName("confirmCreatePassword");
        confirmCreatePassword->setFont(font1);
        confirmCreatePassword->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_4->addWidget(confirmCreatePassword);

        horizontalLayoutWidget = new QWidget(Startwindow);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-30, 160, 851, 80));
        QFont font2;
        font2.setPointSize(16);
        horizontalLayoutWidget->setFont(font2);
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(label_3);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        label->setFont(font3);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(label);

        loginButton = new QPushButton(Startwindow);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(50, 480, 101, 31));
        QFont font4;
        font4.setBold(true);
        loginButton->setFont(font4);
        CAwarningMsgLabel = new QLabel(Startwindow);
        CAwarningMsgLabel->setObjectName("CAwarningMsgLabel");
        CAwarningMsgLabel->setGeometry(QRect(480, 460, 261, 16));
        QFont font5;
        font5.setPointSize(8);
        CAwarningMsgLabel->setFont(font5);
        CAwarningMsgLabel->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);
        verticalLayoutWidget_2 = new QWidget(Startwindow);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(50, 370, 261, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName("label_5");
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout_2->addWidget(label_5);

        loginPassword = new QLineEdit(verticalLayoutWidget_2);
        loginPassword->setObjectName("loginPassword");
        loginPassword->setFont(font1);
        loginPassword->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(loginPassword);

        createButton = new QPushButton(Startwindow);
        createButton->setObjectName("createButton");
        createButton->setGeometry(QRect(480, 480, 101, 31));
        createButton->setFont(font4);
        verticalLayoutWidget = new QWidget(Startwindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(50, 240, 261, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout->addWidget(label_4);

        loginUsername = new QLineEdit(verticalLayoutWidget);
        loginUsername->setObjectName("loginUsername");
        loginUsername->setFont(font1);

        verticalLayout->addWidget(loginUsername);

        LIwarningMsgLabel = new QLabel(Startwindow);
        LIwarningMsgLabel->setObjectName("LIwarningMsgLabel");
        LIwarningMsgLabel->setGeometry(QRect(50, 460, 261, 16));
        LIwarningMsgLabel->setFont(font5);
        LIwarningMsgLabel->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);
        label_6 = new QLabel(Startwindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(90, 40, 391, 51));
        QFont font6;
        font6.setPointSize(18);
        font6.setBold(true);
        label_6->setFont(font6);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(Startwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(560, 20, 100, 100));
        label_2->setMinimumSize(QSize(100, 100));
        label_2->setMaximumSize(QSize(100, 100));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/resources/password-manager.png")));
        label_2->setScaledContents(true);
        line = new QFrame(Startwindow);
        line->setObjectName("line");
        line->setGeometry(QRect(49, 120, 691, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_7 = new QLabel(Startwindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(100, 90, 391, 31));
        QFont font7;
        font7.setPointSize(10);
        label_7->setFont(font7);
        rememberMeCheckBox = new QCheckBox(Startwindow);
        rememberMeCheckBox->setObjectName("rememberMeCheckBox");
        rememberMeCheckBox->setGeometry(QRect(50, 560, 311, 24));
        line_2 = new QFrame(Startwindow);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(50, 530, 691, 20));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        showCApass = new QCheckBox(Startwindow);
        showCApass->setObjectName("showCApass");
        showCApass->setGeometry(QRect(720, 370, 41, 16));
        showCApass->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/resources/hide.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        showCApass->setIcon(icon1);
        showCAconfpass = new QCheckBox(Startwindow);
        showCAconfpass->setObjectName("showCAconfpass");
        showCAconfpass->setGeometry(QRect(720, 430, 41, 16));
        showCAconfpass->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        showCAconfpass->setIcon(icon1);
        showLIpass = new QCheckBox(Startwindow);
        showLIpass->setObjectName("showLIpass");
        showLIpass->setGeometry(QRect(290, 430, 41, 16));
        showLIpass->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        showLIpass->setIcon(icon1);
        showLIpass->raise();
        showCAconfpass->raise();
        showCApass->raise();
        verticalLayoutWidget_3->raise();
        verticalLayoutWidget_4->raise();
        horizontalLayoutWidget->raise();
        loginButton->raise();
        CAwarningMsgLabel->raise();
        verticalLayoutWidget_2->raise();
        createButton->raise();
        verticalLayoutWidget->raise();
        LIwarningMsgLabel->raise();
        label_6->raise();
        label_2->raise();
        line->raise();
        label_7->raise();
        rememberMeCheckBox->raise();
        line_2->raise();
        QWidget::setTabOrder(loginUsername, loginPassword);
        QWidget::setTabOrder(loginPassword, loginButton);
        QWidget::setTabOrder(loginButton, rememberMeCheckBox);
        QWidget::setTabOrder(rememberMeCheckBox, createUsername);
        QWidget::setTabOrder(createUsername, createPassword);
        QWidget::setTabOrder(createPassword, confirmCreatePassword);
        QWidget::setTabOrder(confirmCreatePassword, createButton);

        retranslateUi(Startwindow);

        QMetaObject::connectSlotsByName(Startwindow);
    } // setupUi

    void retranslateUi(QWidget *Startwindow)
    {
        Startwindow->setWindowTitle(QCoreApplication::translate("Startwindow", "Password Manager - Welcome", nullptr));
        label_8->setText(QCoreApplication::translate("Startwindow", " Username", nullptr));
        createUsername->setText(QString());
        label_9->setText(QCoreApplication::translate("Startwindow", " Password", nullptr));
        label_10->setText(QCoreApplication::translate("Startwindow", " Confirm password", nullptr));
        label_3->setText(QCoreApplication::translate("Startwindow", "Log in", nullptr));
        label->setText(QCoreApplication::translate("Startwindow", "Create account", nullptr));
        loginButton->setText(QCoreApplication::translate("Startwindow", "Log in", nullptr));
        CAwarningMsgLabel->setText(QString());
        label_5->setText(QCoreApplication::translate("Startwindow", " Password", nullptr));
        createButton->setText(QCoreApplication::translate("Startwindow", "Create", nullptr));
        label_4->setText(QCoreApplication::translate("Startwindow", " Username", nullptr));
        LIwarningMsgLabel->setText(QString());
        label_6->setText(QCoreApplication::translate("Startwindow", "Welcome to Password Manager", nullptr));
        label_2->setText(QString());
        label_7->setText(QCoreApplication::translate("Startwindow", "Your personal, secure password vault", nullptr));
        rememberMeCheckBox->setText(QCoreApplication::translate("Startwindow", "Remember me and skip this window next time", nullptr));
        showCApass->setText(QString());
        showCAconfpass->setText(QString());
        showLIpass->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Startwindow: public Ui_Startwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
