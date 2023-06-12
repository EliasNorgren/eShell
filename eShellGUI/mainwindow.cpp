#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../eShellBackend/eshellbackend.h"

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
    eShellBackend be;

    QString text = ui->lineEdit->text();
    ui->textBrowser->insertPlainText(text);
}

