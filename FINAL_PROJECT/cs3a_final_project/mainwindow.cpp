#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //ui->lineEdit->setText("This is just a studid fuckin test!\n");

    //They have their own fucking strings....
    //QString str = "hello world";
    //setText won't accept a std::string
    //ui->lineEdit->setText(str);

    //you can also convert from standard string
    //std::string test = "This some dumb shit";
    //ui->lineEdit->setText(QString::fromStdString(test));

    //another option is just passing in a "cstring"
    //std::string yer = "I like C";
    //ui->lineEdit->setText(yer.c_str());
    //btw lineEdit is the little text box that we added
    //in the Forms/mainwindow.ui

    QString store_current = ui->lineEdit->text();
    store_current += "Dicks and balls";
    ui->lineEdit->setText(store_current);
}
