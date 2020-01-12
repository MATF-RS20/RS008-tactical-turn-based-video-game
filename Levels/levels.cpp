#include "levels.h"

GameController createLevel1(QGraphicsScene* scene)
{
    GameController gController;
    //gController.setGrid(new Grid(4, 4));

    Grid* g = new Grid(3,4);
    g->setPos(0, 0);
    scene->addItem(g);
    gController.setGrid(g);

    gController.addUnit(new Warrior(300,10,5,3,3));
    gController.addUnit(new Healer (200,10,5,0,0));

    gController.startGame();
    return gController;
}
