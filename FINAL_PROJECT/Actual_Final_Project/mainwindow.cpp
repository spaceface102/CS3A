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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_displayList_PushButton_clicked()
{
    std::ostringstream output;

    intList.display(output);
    ui->listOutput_TextEdit->setText(output.str().c_str());
}
//EOF

void MainWindow::on_pushBack_PushButton_clicked()
{
    QRadioButton* currentRadio;  //PROC - pointer to current active button

    currentRadio = ActiveRadioButton();
    intList.push_back(currentRadio->text().toInt());
}
//EOF

QRadioButton* MainWindow::ActiveRadioButton(void)
{
    if (ui->int_RadioButton->isChecked())
        return ui->int_RadioButton;
    else if (ui->double_RadioButton->isChecked())
        return ui->double_RadioButton;
    else if (ui->qstring_RadioButton->isChecked())
        return ui->qstring_RadioButton;
    else if (ui->rational_RadioButton->isChecked())
        return ui->rational_RadioButton;
    else if (ui->date_RadioButton->isChecked())
        return ui->date_RadioButton;
    else if (ui->complex_RadioButton->isCheckable())
        return ui->complex_RadioButton;
    else    //default
        return ui->int_RadioButton;
}
