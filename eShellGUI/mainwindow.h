#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../eShellBackend/eshellbackend.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void setBackend(eShellBackend *backend){
        this->backend = backend;
    }
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

private:
    eShellBackend *backend;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
