#include "mainwindow.h"
#include "grid.h"
#include "field.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //logic
    Grid our_grid(2,3);
    std::cout << our_grid << "\n Uspeh!" << std::endl;

    /*Field our_field(1,2);
    std::cout << our_field << "\n Uspeh!" << std::endl;*/


    w.show();
    return a.exec();
}
