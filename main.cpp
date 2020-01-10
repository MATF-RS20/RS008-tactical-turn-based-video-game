#include "gamecontroller.h"
#include "Units/unit.h"
#include "Levels/levels.h"
#include "field.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    //x coordinates in range of (-300, 300)
    //y coordinates in range of (-300, 300)
    scene.setSceneRect(-300, -300, 600, 600);

    //TODO: Dodaj vizuelnu repr. polja u grid-u
    // i ubaci u scenu

    //Adding a field to the scene.
    Field * f = new Field(0, 0);
    f->setPos(0, 0);
    scene.addItem(f);


    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle("Game");
    view.resize(900, 900);
    view.show();

    //TODO: Timer.

    return app.exec();
}
