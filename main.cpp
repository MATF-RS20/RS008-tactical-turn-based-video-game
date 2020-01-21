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
    ui ui = makeUI();

    GameController* gc = createLevel1(ui);
    gc->startGame();

    ui.window->show();

    //TODO: Timer?

    return app.exec();
}
