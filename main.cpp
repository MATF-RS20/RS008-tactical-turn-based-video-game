#include "mainwindow.h"
#include "gamecontroller.h"
#include "grid.h"
#include "field.h"
#include "Units/unit.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //logic
    GameController gController;
    gController.setGrid(new Grid(4, 4));
    gController.addUnit(new Warrior(300,10,5,10,10));
    gController.addUnit(new Healer (200,10,5,10,10));
    gController.startGame();
    std::cout << *(gController.activeUnit()) << std::endl;
    gController.endTurn();
    std::cout << *(gController.activeUnit()) << std::endl;
    gController.endTurn();
    std::cout << *(gController.activeUnit()) << std::endl;


    w.show();
    return a.exec();
}
