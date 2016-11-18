#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test.h"
#include <iostream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_addClient, SIGNAL(clicked()), this, SLOT(form_addClient()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::form_addClient(){
    //std::cout << "a" << std::flush;
    test t;
    t.print();

    ui->tabWidget->setCurrentIndex(1);
}
