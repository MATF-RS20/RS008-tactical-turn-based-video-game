#include "Controller/gamecontroller.h"
#include "Units/unit.h"
#include "Levels/levels.h"
#include "View/ui.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget* window;
    QGraphicsScene* scene;

    std::tie(window, scene) = makeUI();

    Grid* g = new Grid(3,2);
    g->setPos(0, 0);
    scene->addItem(g);

    window->show();

    //TODO: Timer.

    return app.exec();
}
