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
    Player* player3 = new Player("Player3: Laza", Qt::cyan);

    gController->addPlayer(player1);
    gController->addPlayer(player2);
    gController->addPlayer(player3);


    /*
    //Catch tests?
    Warrior a = {5, 3, nullptr};
    Warrior b = {5, 3, nullptr};
    std::cerr << "Equality test: " << (a == a) << std::endl;
    std::cerr << "Equality test: " << !(a == b) << std::endl;
    std::cerr << "Inequality test: " << !(a != a) << std::endl;
    */

    //TODO: Get this from a vector? Get this from a txt/json file?!
    gController->addUnit(new Warrior(3, 2, player1));
    gController->addUnit(new Healer (2, 0, player1));


    gController->addUnit(new Warrior(1, 3, player2));
    gController->addUnit(new Healer (1, 4, player2));


    gController->addUnit(new Warrior(300, 50, 25, 10000, 2, 3, player1, new std::vector<Action*>{new Action("Move", ActionType::move, 0, 1), new Action("Test Kill", ActionType::damage, 300, 10) }));


    gController->addUnit(new Healer (1, 2, player3));

    return gController;
}
