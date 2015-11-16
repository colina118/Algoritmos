#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "polygonwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    polygonwindow pol;
    pol.setModal(true);
    pol.exec();
}
