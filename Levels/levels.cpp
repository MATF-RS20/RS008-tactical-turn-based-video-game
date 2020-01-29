#include "levels.h"

GameController* createLevel1(ui ui)
{
    //TODO: remove this binding after refactor.
    GameController* gController = new GameController(ui);


    Grid* g = new Grid(4,5);
    gController->setGrid(g);

    //TODO: Make a player vector and add the vector to gameController.
    Player* player1 = new Player("Player1: Pera", Qt::blue);
    Player* player2 = new Player("Player2: Zika", Qt::green);

    std::vector<Action*>* warriorActions = new std::vector<Action*>({new Action("Move", 2), new TestAction1("Attack", 5)});
    std::vector<Action*>* healerActions = new std::vector<Action*>({new Action("Move", 1), new TestAction1("Heal", 1), new TestAction1("Heal 2", 2)});

    //TODO: Get this from a vector? Get this from a txt/json file?!
    gController->addUnit(new Warrior(300, 10, 5, 3, 2, player1, warriorActions));
    gController->addUnit(new Healer (200, 10, 5, 2, 0, player1, healerActions));
    gController->addUnit(new Warrior(300, 10, 5, 1, 3, player2, warriorActions));
    gController->addUnit(new Healer (200, 10, 5, 0, 0, player2, healerActions));

    return gController;
}
