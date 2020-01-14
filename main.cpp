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
    std::vector<QPushButton*> * actionButtons;
    */

    auto [window, scene, showInfo, actionButtons] = makeUI();

    GameController gc = createLevel1(scene, showInfo);

    window->show();

    //TODO: Timer.

    return app.exec();
}
