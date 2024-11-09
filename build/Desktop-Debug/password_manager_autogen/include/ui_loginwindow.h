/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

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

class Ui_Loginwindow
{
public:
    QLabel *LIwarningMsgLabel;
    QPushButton *loginButton;
    QCheckBox *showLIpass;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLineEdit *loginPassword;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *welcomeLabel;
    QLabel *label;
    QFrame *line;
    QPushButton *logoutButton;

    void setupUi(QWidget *Loginwindow)
    {
        if (Loginwindow->objectName().isEmpty())
            Loginwindow->setObjectName("Loginwindow");
        Loginwindow->resize(500, 287);
        Loginwindow->setMaximumSize(QSize(500, 400));
        LIwarningMsgLabel = new QLabel(Loginwindow);
        LIwarningMsgLabel->setObjectName("LIwarningMsgLabel");
        LIwarningMsgLabel->setGeometry(QRect(30, 210, 261, 16));
        QFont font;
        font.setPointSize(8);
        LIwarningMsgLabel->setFont(font);
        LIwarningMsgLabel->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);
        loginButton = new QPushButton(Loginwindow);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(30, 230, 101, 31));
        QFont font1;
        font1.setBold(true);
        loginButton->setFont(font1);
        showLIpass = new QCheckBox(Loginwindow);
        showLIpass->setObjectName("showLIpass");
        showLIpass->setGeometry(QRect(270, 180, 41, 16));
        showLIpass->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/resources/hide.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        showLIpass->setIcon(icon);
        verticalLayoutWidget_2 = new QWidget(Loginwindow);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(30, 120, 261, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName("label_5");
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout_2->addWidget(label_5);

        loginPassword = new QLineEdit(verticalLayoutWidget_2);
        loginPassword->setObjectName("loginPassword");
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        loginPassword->setFont(font3);
        loginPassword->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(loginPassword);

        horizontalLayoutWidget = new QWidget(Loginwindow);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 10, 451, 102));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        welcomeLabel = new QLabel(horizontalLayoutWidget);
        welcomeLabel->setObjectName("welcomeLabel");
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(true);
        welcomeLabel->setFont(font4);
        welcomeLabel->setTextFormat(Qt::TextFormat::AutoText);
        welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(welcomeLabel);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(100, 100));
        label->setMaximumSize(QSize(100, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/resources/password-manager.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        line = new QFrame(Loginwindow);
        line->setObjectName("line");
        line->setGeometry(QRect(30, 110, 441, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        logoutButton = new QPushButton(Loginwindow);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(370, 230, 101, 31));
        logoutButton->setFont(font1);
        QWidget::setTabOrder(loginPassword, loginButton);
        QWidget::setTabOrder(loginButton, logoutButton);

        retranslateUi(Loginwindow);

        QMetaObject::connectSlotsByName(Loginwindow);
    } // setupUi

    void retranslateUi(QWidget *Loginwindow)
    {
        Loginwindow->setWindowTitle(QCoreApplication::translate("Loginwindow", "Password Manager - Log in", nullptr));
        LIwarningMsgLabel->setText(QString());
        loginButton->setText(QCoreApplication::translate("Loginwindow", "Log in", nullptr));
        showLIpass->setText(QString());
        label_5->setText(QCoreApplication::translate("Loginwindow", " Password", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("Loginwindow", "Welcome back, User", nullptr));
        label->setText(QString());
        logoutButton->setText(QCoreApplication::translate("Loginwindow", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loginwindow: public Ui_Loginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
