#include "gamecontroller.h"
#include "Units/unit.h"
#include "Levels/levels.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);

    //TODO: Dodaj vizuelnu repr. polja u grid-u
    // i ubaci u scenu


    QGraphicsView view(&scene);

    view.setRenderHint(QPainter::Antialiasing);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle("Game");
    view.resize(1200, 800);
    view.show();

    //logic
    GameController gController = createLevel1();
    std::cout << *(gController.activeUnit()) << std::endl;
    gController.endTurn();
    std::cout << *(gController.activeUnit()) << std::endl;
    gController.endTurn();
    std::cout << *(gController.activeUnit()) << std::endl;


    return app.exec();
}
