/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *NumIn;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *from;
    QSlider *horizontalSlider;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *to;
    QSlider *horizontalSlider_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *convertButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *resultLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1030, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 500, 550));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto")});
        font.setPointSize(12);
        groupBox->setFont(font);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 12, 481, 441));
        layoutWidget->setMinimumSize(QSize(0, 50));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(5, 0, 5, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 40));
        label->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Light")});
        font1.setPointSize(10);
        label->setFont(font1);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label);

        NumIn = new QLineEdit(layoutWidget);
        NumIn->setObjectName("NumIn");
        NumIn->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(NumIn);


        verticalLayout_6->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 40));
        label_2->setMaximumSize(QSize(16777215, 40));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_2->addWidget(label_2);

        from = new QLineEdit(layoutWidget);
        from->setObjectName("from");
        from->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(from);


        verticalLayout_5->addLayout(verticalLayout_2);

        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"     background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 18px;\n"
"     margin: -2px 0; \n"
"     border-radius: 3px;\n"
" }"));
        horizontalSlider->setMinimum(2);
        horizontalSlider->setMaximum(36);
        horizontalSlider->setValue(10);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 40));
        label_3->setMaximumSize(QSize(16777215, 40));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_3->addWidget(label_3);

        to = new QLineEdit(layoutWidget);
        to->setObjectName("to");
        to->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(to);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalSlider_2 = new QSlider(layoutWidget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"     background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 18px;\n"
"     margin: -2px 0; \n"
"     border-radius: 3px;\n"
" }"));
        horizontalSlider_2->setMinimum(2);
        horizontalSlider_2->setMaximum(36);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSlider_2);


        verticalLayout_6->addLayout(verticalLayout_4);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 480, 481, 61));
        layoutWidget1->setMinimumSize(QSize(0, 50));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 0, 5, 0);
        convertButton = new QPushButton(layoutWidget1);
        convertButton->setObjectName("convertButton");
        convertButton->setMinimumSize(QSize(0, 50));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto")});
        font2.setPointSize(10);
        convertButton->setFont(font2);
        convertButton->setCursor(QCursor(Qt::PointingHandCursor));
        convertButton->setMouseTracking(true);
        convertButton->setFocusPolicy(Qt::ClickFocus);
        convertButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #32a848;\n"
"color: white;\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton::hover {\n"
"	background-color: #288539;\n"
"}"));
        convertButton->setAutoDefault(false);

        horizontalLayout->addWidget(convertButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 50));
        pushButton_2->setFont(font2);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #737373;\n"
"	color: white;\n"
"	border-radius: 5px;\n"
"}\n"
"QPushButton::hover {\n"
"	background-color: #525252;\n"
"}"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(0, 50));
        pushButton_3->setFont(font2);
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #737373;\n"
"	color: white;\n"
"	border-radius: 5px;\n"
"}\n"
"QPushButton::hover {\n"
"	background-color: #525252;\n"
"}"));

        horizontalLayout->addWidget(pushButton_3);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(520, 10, 500, 550));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("QScrollArea#PreviewModel{\n"
"    background-color: #282828;\n"
"    border: none;\n"
"}\n"
"\n"
"#modelWidget{\n"
"    border: 2px solid #00aaff;\n"
"}"));
        scrollArea = new QScrollArea(groupBox_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(9, 34, 481, 505));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 479, 503));
        resultLabel = new QTextEdit(scrollAreaWidgetContents);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setGeometry(QRect(0, 0, 481, 505));
        resultLabel->setFont(font);
        resultLabel->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"	border:none;\n"
"}"));
        resultLabel->setReadOnly(true);
        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Converter", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter number", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "From base", nullptr));
        from->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "To base", nullptr));
        to->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        convertButton->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Swap", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
