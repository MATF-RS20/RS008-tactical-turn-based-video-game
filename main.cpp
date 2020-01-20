#include "Controller/gamecontroller.h"
#include "Units/unit.h"
#include "Levels/levels.h"
#include "View/ui.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*
    QWidget* window;
    QGraphicsScene* scene;
    QLabel* showInfo;
    QLabel* playerLabel;
    std::vector<ActionButton*> * actionButtons;
    QPushButton* pb_endTurn;
    */
    auto [window, scene, showInfo, playerLabel, actionButtons, pb_endTurn] = makeUI();

    GameController* gc = createLevel1(scene, showInfo, playerLabel, actionButtons, pb_endTurn);
    gc->startGame();

    window->show();

    //TODO: Timer?

    return app.exec();
}
