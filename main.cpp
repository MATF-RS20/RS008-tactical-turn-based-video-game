#include "mainwindow.h"
#include "grid.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //logic
    Grid our_grid(12,13);
    std::cout << our_grid << "\n Uspeh!" << std::endl;


    w.show();
    return a.exec();
}
