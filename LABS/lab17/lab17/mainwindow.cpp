#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <cstdio>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tempSlider->setRange(-50, 150);
    ui->tempSlider->setSliderPosition(50); //set to the middle
    ui->tempInput->setText("0");
    ui->tempOutput->setText("0");
    ui->celsius_to_Fahren->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double celsius;
    double fahren;
    char convertDoubleToCstring[32];

    if (ui->celsius_to_Fahren->isChecked())
    {
        celsius = ui->tempInput->text().toDouble();
        fahren = (celsius*1.80) + 32;
        ui->tempSlider->setSliderPosition(fahren);

        snprintf(convertDoubleToCstring, 31, "%.0lf", fahren);
        ui->tempOutput->setText(convertDoubleToCstring);
        ui->tempSlider->setSliderPosition(fahren);
    }
    else //fahren_to_celsius
    {
        fahren = ui->tempInput->text().toDouble();
        celsius = (fahren-32)/1.80;
        ui->tempSlider->setSliderPosition(celsius);

        snprintf(convertDoubleToCstring, 31, "%.0lf", celsius);
        ui->tempOutput->setText(convertDoubleToCstring);
        ui->tempSlider->setSliderPosition(celsius);
    }
}

void MainWindow::on_tempSlider_sliderReleased()
{
    std::cerr << "Releasing the tempSlider\n";
    std::cerr << "Current positon of tempSlider: "
    << ui->tempSlider->sliderPosition() << "\n";
}

