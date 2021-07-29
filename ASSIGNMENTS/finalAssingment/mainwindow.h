#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linkedList_Wrapper.h"
#include "textToTypeConvert.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_int_RadioButton_clicked();

    void on_double_RadioButton_clicked();

    void on_string_RadioButton_clicked();

    void on_rational_RadioButton_clicked();

    void on_date_RadioButton_clicked();

    void on_complex_RadioButton_clicked();

    void on_sort_PushButton_clicked();

    void on_removeDuplicates_PushButton_clicked();

    void on_popFront_PushButton_clicked();

    void on_pushBack_PushButton_clicked();

    void on_pushFront_PushButton_clicked();

    void on_insertSorted_PushButton_clicked();

    void on_insert_PushButton_clicked();

    void on_displayPortion_PushButton_clicked();

    void on_makeCopy_PushButton_clicked();

    void on_chooseCopy_PushButton_clicked();

    void on_displayList_PushButton_clicked();

private:
    /**************
    **  HELPERS  **
    **************/
    Ui::MainWindow *ui;

//MINE FIELDS
private:
    CurrentLinkedList_Handler* currentList; //PROC - Interface for all the 
                                            //LinkedList_Wrapper objects

    //Each different type handled by this program gets its own
    //LinkedList_Wrapper object, which must define a text 
    //convertion.
    LinkedList_Wrapper<int>     intList = textConvert::toInt;
    LinkedList_Wrapper<double>  doubleList = textConvert::toDouble;
    LinkedList_Wrapper<std::string> stringList = textConvert::toString;
    LinkedList_Wrapper<Rational> rationalList = textConvert::toRational;
    LinkedList_Wrapper<Date>    dateList = textConvert::toDate;
    LinkedList_Wrapper<Complex> complexList = textConvert::toComplex;

private:
    void updateListOutputFull(void);
};
#endif // MAINWINDOW_H
