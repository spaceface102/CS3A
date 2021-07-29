#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //My Init
    ui->int_RadioButton->setChecked(true); //set default radio button
    ui->currentCopyNum_LCDNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->currentCopyNum_LCDNumber->display(1); //minium value to display

    currentList = &intList;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//All the radio buttons do is change what
//currentList is pointing to: uses polymorphisim
//to do specific task
void MainWindow::on_int_RadioButton_clicked()
{
    currentList = &intList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}


void MainWindow::on_double_RadioButton_clicked()
{
    currentList = &doubleList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}


void MainWindow::on_string_RadioButton_clicked()
{
    currentList = &stringList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}


void MainWindow::on_rational_RadioButton_clicked()
{
    currentList = &rationalList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}


void MainWindow::on_date_RadioButton_clicked()
{
    currentList = &dateList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}


void MainWindow::on_complex_RadioButton_clicked()
{
    currentList = &complexList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}


void MainWindow::on_sort_PushButton_clicked()
{
    currentList->sort();
    updateListOutputFull();
}


void MainWindow::on_removeDuplicates_PushButton_clicked()
{
    currentList->removeDuplicates();
    updateListOutputFull();
}


void MainWindow::on_popFront_PushButton_clicked()
{
    currentList->popFront();
    updateListOutputFull();
}


void MainWindow::on_pushBack_PushButton_clicked()
{
    currentList->pushBack(
        ui->pushBackInput_LineEdit->text().toStdString().c_str()
    );
    updateListOutputFull();
}


void MainWindow::on_pushFront_PushButton_clicked()
{
    currentList->pushFront(
        ui->pushFrontInput_LineEdit->text().toStdString().c_str()
    );
    updateListOutputFull();
}


void MainWindow::on_insertSorted_PushButton_clicked()
{
    currentList->insertSorted(
        ui->insertSortedInput_LineEdit->text().toStdString().c_str()
    );
    updateListOutputFull();
}


void MainWindow::on_insert_PushButton_clicked()
{
    currentList->insert(
        ui->insertNodeInput_LineEdit->text().toStdString().c_str(),
        ui->insertValueInput_LineEdit->text().toStdString().c_str()
    );
    updateListOutputFull();
}


void MainWindow::on_displayPortion_PushButton_clicked()
{
    std::ostringstream out;

    currentList->display(
        out,
        ui->startInputPortionList_LineEdit->text().toStdString().c_str(),
        ui->endInputPortionList_LineEdit->text().toStdString().c_str()
        );

    ui->listOutput_TextEdit->setText(out.str().c_str());
}


void MainWindow::on_makeCopy_PushButton_clicked()
{
    currentList->makeCopyOfActiveList();
}


void MainWindow::on_chooseCopy_PushButton_clicked()
{

    currentList->setNextListAsActive();
    //+1 since getActiveListNumber returns "index" which
    //starts counting at 0.
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));

    updateListOutputFull();
}

void MainWindow::on_displayList_PushButton_clicked()
{
    updateListOutputFull();
}

void MainWindow::updateListOutputFull(void)
{
    std::ostringstream out;
    currentList->display(out);
    ui->listOutput_TextEdit->setText(out.str().c_str());
}
