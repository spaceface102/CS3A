#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QRadioButton>
#include "myVector.h"
#include "linkedList.h"
#include "date.h"
#include "rational.h"
#include "complex.h"

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
    void on_displayList_PushButton_clicked();

    void on_pushBack_PushButton_clicked();

    void on_chooseCopy_PushButton_clicked();

    void on_int_RadioButton_clicked();

    void on_makeCopy_PushButton_clicked();

private:
    Ui::MainWindow *ui;

//MINE
private: //fiedls
    MyVector<LinkedList<int>> intListVector;
    MyVector<LinkedList<double>> doubleListVector;
    MyVector<LinkedList<QString>> qStringListVector;
    MyVector<LinkedList<Rational>> rationalListVector;
    MyVector<LinkedList<Complex>> complexListVector;
    MyVector<LinkedList<Date>> dateListVector;

    int listCopyNumber;    //TRACK - which linked list we are using
};
#endif // MAINWINDOW_H
