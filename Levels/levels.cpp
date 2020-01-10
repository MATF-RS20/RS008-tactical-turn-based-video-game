#include "levels.h"

GameController createLevel1()
{
    GameController gController;
    //gController.setGrid(new Grid(4, 4));
    gController.addUnit(new Warrior(300,10,5,10,10));
    gController.addUnit(new Healer (200,10,5,10,10));
    gController.startGame();
    return gController;
}
