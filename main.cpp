#include "Controller/gamecontroller.h"
#include "Units/unit.h"
#include "Levels/levels.h"
#include "field.h"

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget* window = new QWidget();

    QGraphicsScene* scene = new QGraphicsScene(window);
    scene->setSceneRect(-200, -200, 400, 400);

    QGraphicsView* view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    //view.setWindowTitle("Game");
    view->resize(600, 600);
    //view.show();

    Grid g = Grid(3,2, scene);
    /*Field * f = new Field(0, 0, 40);
    f->setPos(0, 0);
    scene.addItem(f);*/

    QVBoxLayout* outer = new QVBoxLayout(window);
    QPushButton* pb_endTurn = new QPushButton("End turn", window);



    outer->addWidget(view);
    outer->addWidget(pb_endTurn);
    window->setLayout(outer);
    window->show();

    //TODO: Timer.

    return app.exec();
}
