#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QRadioButton>
#include <vector>
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

private:
    Ui::MainWindow *ui;

//MINE
private: //helper constants
    enum class ActiveRadio {INT, DOUBLE, QSTRING, RATIONAL,
                            COMPLEX, DATE};

private: //fiedls
    std::vector<LinkedList<int>> intListVector;
    std::vector<LinkedList<double>> doubleListVector;
    std::vector<LinkedList<QString>> qStringListVector;
    std::vector<LinkedList<Rational>> rationalListVector;
    std::vector<LinkedList<Complex>> complexListVector;
    std::vector<LinkedList<Date>> dateListVector;

    LinkedList<int> intList;
private: //helper methods
    QRadioButton* ActiveRadioButton(void);
};
#endif // MAINWINDOW_H
