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
    /*Grid our_grid(2,3);
    std::cout << our_grid << "\n Success!" << std::endl;

    Warrior w1(300,10,5,10,10);
    std::cout << w1 << "\n Success!" << std::endl;

    Healer h1(300,10,5,10,10);
    std::cout << h1 << "\n Success!" << std::endl;

    auto u1 = static_cast<Unit>(w1);
    std::cout << u1 << std::endl;

    u1.updateHealth(-250);
    std::cout << u1 << std::endl;
    w1.updateHealth(+500);
    std::cout << u1 << std::endl;
    w1.updateHealth(-900);
    std::cout << w1 << std::endl;
    std::cout << u1 << std::endl;
    u1.updateHealth(-250);
    std::cout << u1 << std::endl;*/

    GameController gController;
    gController.setGrid(new Grid(4, 4));
    gController.addUnit(Warrior(300,10,5,10,10));
    gController.addUnit(Healer (200,10,5,10,10));\
    gController.startGame();
    //TODO: cout logs Unit instead of Warrior.
    std::cout << *(gController.activeUnit()) << std::endl;
    gController.endTurn();
    std::cout << *(gController.activeUnit()) << std::endl;



    /*Field our_field(1,2);
    std::cout << our_field << "\n Uspeh!" << std::endl;*/


    w.show();
    return a.exec();
}
