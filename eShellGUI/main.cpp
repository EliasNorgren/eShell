#include "mainwindow.h"

#include <QApplication>

#include "../eShellBackend/eshellbackend.h"

int main(int argc, char *argv[])
{
    eShellBackend backend;
    QApplication a(argc, argv);
    MainWindow w;
    w.setBackend(&backend);
    w.show();
    return a.exec();
}
