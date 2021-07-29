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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *displayList_PushButton;
    QPushButton *chooseCopy_PushButton;
    QLCDNumber *currentCopyNum_LCDNumber;
    QPushButton *pushBack_PushButton;
    QLineEdit *pushBackInput_LineEdit;
    QPushButton *pushFront_PushButton;
    QLineEdit *pushFrontInput_LineEdit;
    QPushButton *insertSorted_PushButton;
    QLineEdit *insertSortedInput_LineEdit;
    QPushButton *popFront_PushButton;
    QTextEdit *listOutput_TextEdit;
    QPushButton *sort_PushButton;
    QPushButton *removeDuplicates_PushButton;
    QGroupBox *insert_GroupBox;
    QLabel *value_Label;
    QLabel *node_Label;
    QLineEdit *insertValueInput_LineEdit;
    QLineEdit *insertNodeInput_LineEdit;
    QGroupBox *selectPortion_GroupBox;
    QLabel *start_Label;
    QLineEdit *endInputPortionList_LineEdit;
    QLineEdit *startInputPortionList_LineEdit;
    QLabel *end_Label;
    QGroupBox *nodeType_GroupBox;
    QRadioButton *complex_RadioButton;
    QRadioButton *qstring_RadioButton;
    QRadioButton *double_RadioButton;
    QRadioButton *rational_RadioButton;
    QRadioButton *int_RadioButton;
    QRadioButton *date_RadioButton;
    QMenuBar *menubar;
    QMenu *menuOsbaldo_Gonzalez_s_Linked_List_Display;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(587, 528);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        displayList_PushButton = new QPushButton(centralwidget);
        displayList_PushButton->setObjectName(QString::fromUtf8("displayList_PushButton"));
        displayList_PushButton->setGeometry(QRect(20, 10, 221, 21));
        chooseCopy_PushButton = new QPushButton(centralwidget);
        chooseCopy_PushButton->setObjectName(QString::fromUtf8("chooseCopy_PushButton"));
        chooseCopy_PushButton->setGeometry(QRect(20, 40, 111, 24));
        currentCopyNum_LCDNumber = new QLCDNumber(centralwidget);
        currentCopyNum_LCDNumber->setObjectName(QString::fromUtf8("currentCopyNum_LCDNumber"));
        currentCopyNum_LCDNumber->setGeometry(QRect(150, 40, 91, 23));
        pushBack_PushButton = new QPushButton(centralwidget);
        pushBack_PushButton->setObjectName(QString::fromUtf8("pushBack_PushButton"));
        pushBack_PushButton->setGeometry(QRect(140, 370, 101, 24));
        pushBackInput_LineEdit = new QLineEdit(centralwidget);
        pushBackInput_LineEdit->setObjectName(QString::fromUtf8("pushBackInput_LineEdit"));
        pushBackInput_LineEdit->setGeometry(QRect(20, 370, 113, 24));
        pushFront_PushButton = new QPushButton(centralwidget);
        pushFront_PushButton->setObjectName(QString::fromUtf8("pushFront_PushButton"));
        pushFront_PushButton->setGeometry(QRect(140, 400, 101, 24));
        pushFrontInput_LineEdit = new QLineEdit(centralwidget);
        pushFrontInput_LineEdit->setObjectName(QString::fromUtf8("pushFrontInput_LineEdit"));
        pushFrontInput_LineEdit->setGeometry(QRect(20, 400, 113, 24));
        insertSorted_PushButton = new QPushButton(centralwidget);
        insertSorted_PushButton->setObjectName(QString::fromUtf8("insertSorted_PushButton"));
        insertSorted_PushButton->setGeometry(QRect(140, 430, 101, 24));
        insertSortedInput_LineEdit = new QLineEdit(centralwidget);
        insertSortedInput_LineEdit->setObjectName(QString::fromUtf8("insertSortedInput_LineEdit"));
        insertSortedInput_LineEdit->setGeometry(QRect(20, 430, 113, 24));
        popFront_PushButton = new QPushButton(centralwidget);
        popFront_PushButton->setObjectName(QString::fromUtf8("popFront_PushButton"));
        popFront_PushButton->setGeometry(QRect(20, 340, 221, 24));
        listOutput_TextEdit = new QTextEdit(centralwidget);
        listOutput_TextEdit->setObjectName(QString::fromUtf8("listOutput_TextEdit"));
        listOutput_TextEdit->setGeometry(QRect(20, 90, 221, 151));
        sort_PushButton = new QPushButton(centralwidget);
        sort_PushButton->setObjectName(QString::fromUtf8("sort_PushButton"));
        sort_PushButton->setGeometry(QRect(20, 280, 221, 24));
        removeDuplicates_PushButton = new QPushButton(centralwidget);
        removeDuplicates_PushButton->setObjectName(QString::fromUtf8("removeDuplicates_PushButton"));
        removeDuplicates_PushButton->setGeometry(QRect(20, 310, 221, 24));
        insert_GroupBox = new QGroupBox(centralwidget);
        insert_GroupBox->setObjectName(QString::fromUtf8("insert_GroupBox"));
        insert_GroupBox->setGeometry(QRect(250, 370, 120, 80));
        value_Label = new QLabel(insert_GroupBox);
        value_Label->setObjectName(QString::fromUtf8("value_Label"));
        value_Label->setGeometry(QRect(70, 30, 58, 16));
        node_Label = new QLabel(insert_GroupBox);
        node_Label->setObjectName(QString::fromUtf8("node_Label"));
        node_Label->setGeometry(QRect(10, 30, 58, 16));
        insertValueInput_LineEdit = new QLineEdit(insert_GroupBox);
        insertValueInput_LineEdit->setObjectName(QString::fromUtf8("insertValueInput_LineEdit"));
        insertValueInput_LineEdit->setGeometry(QRect(70, 50, 41, 24));
        insertNodeInput_LineEdit = new QLineEdit(insert_GroupBox);
        insertNodeInput_LineEdit->setObjectName(QString::fromUtf8("insertNodeInput_LineEdit"));
        insertNodeInput_LineEdit->setGeometry(QRect(10, 50, 41, 24));
        selectPortion_GroupBox = new QGroupBox(centralwidget);
        selectPortion_GroupBox->setObjectName(QString::fromUtf8("selectPortion_GroupBox"));
        selectPortion_GroupBox->setGeometry(QRect(250, 280, 131, 91));
        start_Label = new QLabel(selectPortion_GroupBox);
        start_Label->setObjectName(QString::fromUtf8("start_Label"));
        start_Label->setGeometry(QRect(10, 30, 58, 16));
        endInputPortionList_LineEdit = new QLineEdit(selectPortion_GroupBox);
        endInputPortionList_LineEdit->setObjectName(QString::fromUtf8("endInputPortionList_LineEdit"));
        endInputPortionList_LineEdit->setGeometry(QRect(60, 60, 61, 24));
        startInputPortionList_LineEdit = new QLineEdit(selectPortion_GroupBox);
        startInputPortionList_LineEdit->setObjectName(QString::fromUtf8("startInputPortionList_LineEdit"));
        startInputPortionList_LineEdit->setGeometry(QRect(60, 30, 61, 24));
        end_Label = new QLabel(selectPortion_GroupBox);
        end_Label->setObjectName(QString::fromUtf8("end_Label"));
        end_Label->setGeometry(QRect(10, 60, 58, 16));
        nodeType_GroupBox = new QGroupBox(centralwidget);
        nodeType_GroupBox->setObjectName(QString::fromUtf8("nodeType_GroupBox"));
        nodeType_GroupBox->setGeometry(QRect(250, 90, 121, 151));
        complex_RadioButton = new QRadioButton(nodeType_GroupBox);
        complex_RadioButton->setObjectName(QString::fromUtf8("complex_RadioButton"));
        complex_RadioButton->setGeometry(QRect(10, 120, 100, 22));
        qstring_RadioButton = new QRadioButton(nodeType_GroupBox);
        qstring_RadioButton->setObjectName(QString::fromUtf8("qstring_RadioButton"));
        qstring_RadioButton->setGeometry(QRect(10, 60, 100, 22));
        double_RadioButton = new QRadioButton(nodeType_GroupBox);
        double_RadioButton->setObjectName(QString::fromUtf8("double_RadioButton"));
        double_RadioButton->setGeometry(QRect(10, 40, 100, 22));
        rational_RadioButton = new QRadioButton(nodeType_GroupBox);
        rational_RadioButton->setObjectName(QString::fromUtf8("rational_RadioButton"));
        rational_RadioButton->setGeometry(QRect(10, 80, 100, 22));
        int_RadioButton = new QRadioButton(nodeType_GroupBox);
        int_RadioButton->setObjectName(QString::fromUtf8("int_RadioButton"));
        int_RadioButton->setGeometry(QRect(10, 20, 100, 22));
        date_RadioButton = new QRadioButton(nodeType_GroupBox);
        date_RadioButton->setObjectName(QString::fromUtf8("date_RadioButton"));
        date_RadioButton->setGeometry(QRect(10, 100, 100, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 587, 21));
        menuOsbaldo_Gonzalez_s_Linked_List_Display = new QMenu(menubar);
        menuOsbaldo_Gonzalez_s_Linked_List_Display->setObjectName(QString::fromUtf8("menuOsbaldo_Gonzalez_s_Linked_List_Display"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOsbaldo_Gonzalez_s_Linked_List_Display->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        displayList_PushButton->setText(QCoreApplication::translate("MainWindow", "Display Linked List", nullptr));
        chooseCopy_PushButton->setText(QCoreApplication::translate("MainWindow", "Choose Copy", nullptr));
        pushBack_PushButton->setText(QCoreApplication::translate("MainWindow", "Push Back", nullptr));
        pushFront_PushButton->setText(QCoreApplication::translate("MainWindow", "Push Front", nullptr));
        insertSorted_PushButton->setText(QCoreApplication::translate("MainWindow", "Insert Sorted", nullptr));
        popFront_PushButton->setText(QCoreApplication::translate("MainWindow", "Pop Front", nullptr));
        sort_PushButton->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        removeDuplicates_PushButton->setText(QCoreApplication::translate("MainWindow", "Remove Duplicates", nullptr));
        insert_GroupBox->setTitle(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        value_Label->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        node_Label->setText(QCoreApplication::translate("MainWindow", "Node", nullptr));
        selectPortion_GroupBox->setTitle(QCoreApplication::translate("MainWindow", "Select Portion", nullptr));
        start_Label->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        end_Label->setText(QCoreApplication::translate("MainWindow", "End", nullptr));
        nodeType_GroupBox->setTitle(QCoreApplication::translate("MainWindow", "Choose Node Type", nullptr));
        complex_RadioButton->setText(QCoreApplication::translate("MainWindow", "Complex", nullptr));
        qstring_RadioButton->setText(QCoreApplication::translate("MainWindow", "QString", nullptr));
        double_RadioButton->setText(QCoreApplication::translate("MainWindow", "Double", nullptr));
        rational_RadioButton->setText(QCoreApplication::translate("MainWindow", "Rational", nullptr));
        int_RadioButton->setText(QCoreApplication::translate("MainWindow", "Int", nullptr));
        date_RadioButton->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        menuOsbaldo_Gonzalez_s_Linked_List_Display->setTitle(QCoreApplication::translate("MainWindow", "Osbaldo Gonzalez's Linked List Display", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
