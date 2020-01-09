#include "mainwindow.h"
#include "gamecontroller.h"
#include "Units/unit.h"
#include "Levels/levels.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //logic
    GameController gController = createLevel1();
    std::cout << *(gController.activeUnit()) << std::endl;
    gController.endTurn();
    std::cout << *(gController.activeUnit()) << std::endl;
    gController.endTurn();
    std::cout << *(gController.activeUnit()) << std::endl;


    w.show();
    return a.exec();
}
