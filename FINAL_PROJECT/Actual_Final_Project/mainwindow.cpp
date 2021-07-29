#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //My Init
    ui->int_RadioButton->setChecked(true); //set default radio button
    ui->currentCopyNum_LCDNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->currentCopyNum_LCDNumber->display(1);   //minium value to display
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_displayList_PushButton_clicked()
{
    std::ostringstream output;

    intListVector.at(0).display(output);
    ui->listOutput_TextEdit->setText(output.str().c_str());
}
//EOF

void MainWindow::on_pushBack_PushButton_clicked()
{
    //First I have to figure out clean way to choose
    intListVector.at(0).push_back(ui->pushBackInput_LineEdit->text().toInt());
}
//EOF

void MainWindow::on_chooseCopy_PushButton_clicked()
{
    ui->currentCopyNum_LCDNumber->display(
    (++listCopyNumber)
    );
}

void MainWindow::on_int_RadioButton_clicked()
{
    listCopyNumber = 0;
}


void MainWindow::on_makeCopy_PushButton_clicked()
{

}

/*
static void updateDisplay(QLCDNumber* lcd, int number)
{
    lcd->display(number);
}
*/
