#include "levels.h"
#include "actionPresets.h"

GameController* createLevel1(QGraphicsScene* scene, QLabel* showInfo,std::vector<ActionButton*> * actionButtons, QPushButton* pb_endTurn)
{
    GameController* gController = new GameController(nullptr, pb_endTurn, showInfo);


    Grid* g = new Grid(4,5, nullptr, showInfo);
    g->setPos(0, 0);
    scene->addItem(g);
    gController->setGrid(g);

    for (auto button: *actionButtons)
    {
        gController->add_pb_Action(button);
    }
    delete actionButtons; //this deleted the vector, not the actionButtons whose pointers were inside.


    //Adding Units to gController

    Player* player1 = new Player("Player1: Pera", Qt::blue);
    Player* player2 = new Player("Player2: Zika", Qt::green);
    //
    Unit* tmp_unit;
    tmp_unit = new Warrior(300, 10, 5, 3, 2, player1, warriorActions);
        gController->addUnit(tmp_unit);
        scene->addItem(tmp_unit);

    tmp_unit = new Healer (200, 10, 5, 2, 0, player1, healerActions);
        gController->addUnit(tmp_unit);
        scene->addItem(tmp_unit);


    tmp_unit = new Warrior(300, 10, 5, 1, 3, player2, warriorActions);
        gController->addUnit(tmp_unit);
        scene->addItem(tmp_unit);

    tmp_unit = new Healer (200, 10, 5, 0, 0, player2, healerActions);
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
