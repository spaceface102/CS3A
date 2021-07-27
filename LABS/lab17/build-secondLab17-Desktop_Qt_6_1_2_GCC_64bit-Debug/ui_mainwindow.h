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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *celText_LineEdit;
    QLineEdit *fahText_LineEdit;
    QSlider *celTemp_Slider;
    QSlider *fahTemp_Slider;
    QLabel *celLable;
    QLabel *fahLable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 168);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        celText_LineEdit = new QLineEdit(centralwidget);
        celText_LineEdit->setObjectName(QString::fromUtf8("celText_LineEdit"));
        celText_LineEdit->setGeometry(QRect(20, 20, 41, 31));
        fahText_LineEdit = new QLineEdit(centralwidget);
        fahText_LineEdit->setObjectName(QString::fromUtf8("fahText_LineEdit"));
        fahText_LineEdit->setGeometry(QRect(20, 70, 41, 31));
        celTemp_Slider = new QSlider(centralwidget);
        celTemp_Slider->setObjectName(QString::fromUtf8("celTemp_Slider"));
        celTemp_Slider->setGeometry(QRect(90, 30, 160, 16));
        celTemp_Slider->setOrientation(Qt::Horizontal);
        fahTemp_Slider = new QSlider(centralwidget);
        fahTemp_Slider->setObjectName(QString::fromUtf8("fahTemp_Slider"));
        fahTemp_Slider->setGeometry(QRect(90, 80, 160, 16));
        fahTemp_Slider->setOrientation(Qt::Horizontal);
        celLable = new QLabel(centralwidget);
        celLable->setObjectName(QString::fromUtf8("celLable"));
        celLable->setGeometry(QRect(260, 30, 58, 16));
        fahLable = new QLabel(centralwidget);
        fahLable->setObjectName(QString::fromUtf8("fahLable"));
        fahLable->setGeometry(QRect(260, 80, 58, 16));
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
        celLable->setText(QCoreApplication::translate("MainWindow", "\302\260C", nullptr));
        fahLable->setText(QCoreApplication::translate("MainWindow", "\302\260F", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
