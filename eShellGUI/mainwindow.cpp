#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "A2DD.h"

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
    QString text = ui->lineEdit->text();
    A2DD adder(1,2);
    int res = adder.getSum();
//    ui->textBrowser->insertPlainText(text);
    ui->textBrowser->insertPlainText(QString::number(res));
}

