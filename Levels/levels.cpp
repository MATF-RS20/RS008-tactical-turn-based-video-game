#include "levels.h"

GameController createLevel1(QGraphicsScene* scene)
{
    GameController gController;
    //gController.setGrid(new Grid(4, 4));

    Grid* g = new Grid(3,4);
    g->setPos(0, 0);
    scene->addItem(g);
    gController.setGrid(g);

    gController.addUnit(new Warrior(300,10,5,2,2));
    std::cerr << gController.addUnit(new Healer (200,10,5,0,0)) << std::endl;

    //TODO add CATCH tests!

    //This shouldn't be added - bad index. Output = false!
    std::cerr << gController.addUnit(new Healer (200,10,5,5,5)) << std::endl;
    std::cerr << gController.addUnit(new Healer (200,10,5,3,3)) << std::endl;

    gController.startGame();
    return gController;
}
