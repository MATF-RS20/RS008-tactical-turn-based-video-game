#include "levels.h"

GameController* createLevel1(QGraphicsScene* scene, QLabel* showInfo, QPushButton* pb_endTurn)
{
    GameController* gController = new GameController(nullptr, pb_endTurn, showInfo);
    //gController.setGrid(new Grid(4, 4));

    Grid* g = new Grid(3,4, nullptr, showInfo);
    g->setPos(0, 0);
    scene->addItem(g);
    gController->setGrid(g);

    Unit* tmp_unit = new Warrior(300,10,5,2,2);
    gController->addUnit(tmp_unit);
    scene->addItem(tmp_unit);
    tmp_unit = new Healer (200,10,5,0,0);
    gController->addUnit(tmp_unit);
    scene->addItem(tmp_unit);

    /*
    //TODO: add CATCH tests!
    //This shouldn't be added - bad index. Output = false!
    std::cerr << gController->addUnit(new Healer (200,10,5,5,5)) << std::endl;
    std::cerr << gController->addUnit(new Healer (200,10,5,3,3)) << std::endl;
    */

    return gController;
}
