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
    gController->addUnit(new Healer (0, 0, player2));

    return gController;
}
