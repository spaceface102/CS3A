/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QRadioButton *celsius_to_Fahren;
    QRadioButton *fahren_to_Celsius;
    QPushButton *pushButton;
    QSlider *tempSlider;
    QLineEdit *tempInput;
    QLineEdit *tempOutput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 267);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        celsius_to_Fahren = new QRadioButton(centralwidget);
        celsius_to_Fahren->setObjectName(QString::fromUtf8("celsius_to_Fahren"));
        celsius_to_Fahren->setGeometry(QRect(150, 90, 121, 22));
        fahren_to_Celsius = new QRadioButton(centralwidget);
        fahren_to_Celsius->setObjectName(QString::fromUtf8("fahren_to_Celsius"));
        fahren_to_Celsius->setGeometry(QRect(150, 130, 121, 22));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 50, 111, 24));
        tempSlider = new QSlider(centralwidget);
        tempSlider->setObjectName(QString::fromUtf8("tempSlider"));
        tempSlider->setGeometry(QRect(30, 170, 251, 16));
        tempSlider->setOrientation(Qt::Horizontal);
        tempInput = new QLineEdit(centralwidget);
        tempInput->setObjectName(QString::fromUtf8("tempInput"));
        tempInput->setGeometry(QRect(40, 90, 51, 24));
        tempOutput = new QLineEdit(centralwidget);
        tempOutput->setObjectName(QString::fromUtf8("tempOutput"));
        tempOutput->setGeometry(QRect(40, 130, 51, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        celsius_to_Fahren->setText(QCoreApplication::translate("MainWindow", "Celsius to Fahren", nullptr));
        fahren_to_Celsius->setText(QCoreApplication::translate("MainWindow", "Fahren to Celcius", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start Conversion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
