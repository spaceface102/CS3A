#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->celText_LineEdit->setText("0");
    ui->fahText_LineEdit->setText("32");
    ui->celTemp_Slider->setRange(-100, 150);
    ui->fahTemp_Slider->setRange(-100, 150);
    ui->celTemp_Slider->setSliderPosition(0);  //set to init temp
    ui->fahTemp_Slider->setSliderPosition(32); //set to init temp
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_celTemp_Slider_sliderMoved(int position)
{
    int celsius;
    int fahren;
    celsius = position;
    fahren = 32 + (celsius*9)/5;

    ui->celText_LineEdit->setText(QString::number(celsius));
    ui->fahText_LineEdit->setText(QString::number(fahren));
    ui->fahTemp_Slider->setSliderPosition(fahren);
}

void MainWindow::on_fahTemp_Slider_sliderMoved(int position)
{
    int celsius;
    int fahren;
    fahren = position;
    celsius = ((fahren - 32)*5)/9;

    ui->celText_LineEdit->setText(QString::number(celsius));
    ui->fahText_LineEdit->setText(QString::number(fahren));
    ui->celTemp_Slider->setSliderPosition(celsius);
}


void MainWindow::on_fahText_LineEdit_textChanged(const QString& newText)
{
    int fahren; //value held in text box;
    int currentCursorPostion;

    if (newText.length() == 0)  //empty text box
        return;

    //just began to set negaitve input
    if (newText.at(0) == '-' && newText.length() == 1)
        return;

    currentCursorPostion = ui->fahText_LineEdit->cursorPosition();
    fahren = newText.toInt();
    ui->fahTemp_Slider->setSliderPosition(fahren);
    MainWindow::on_fahTemp_Slider_sliderMoved(fahren);
    ui->fahText_LineEdit->setCursorPosition(currentCursorPostion);
}


void MainWindow::on_celText_LineEdit_textChanged(const QString& newText)
{
    /*
    int celsius; //value held in text box;
    int currentCursorPostion;

    if (newText.length() == 0)  //empty text box
        return;

    //just began to set negaitve input
    if (newText.at(0) == '-' && newText.length() == 1)
        return;

    currentCursorPostion = ui->celText_LineEdit->cursorPosition();
    celsius = newText.toInt();
    ui->fahTemp_Slider->setSliderPosition(celsius);
    MainWindow::on_celTemp_Slider_sliderMoved(celsius);
    ui->celText_LineEdit->setCursorPosition(currentCursorPostion);
    */
}

