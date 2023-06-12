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

    QString text = ui->lineEdit->text();
    string res = this->backend->runCommand(text.toStdString());
    ui->textBrowser->insertPlainText(QString::fromStdString(res));
}

