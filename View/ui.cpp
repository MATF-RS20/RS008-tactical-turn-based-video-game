#include "ui.h"


QWidget* makeUI()
{
    QWidget* window = new QWidget();

    QGraphicsScene* scene = new QGraphicsScene(window);
    scene->setSceneRect(-200, -200, 400, 400);

    QGraphicsView* view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    //view.setWindowTitle("Game");
    view->resize(600, 600);
    //view.show();

    Grid* g = new Grid(3,2);
    /*Field * f = new Field(0, 0, 40);
    f->setPos(0, 0);
    scene.addItem(f);*/
    scene->addItem(g);

    QVBoxLayout* outer = new QVBoxLayout(window);
    QPushButton* pb_endTurn = new QPushButton("End turn", window);



    outer->addWidget(view);
    outer->addWidget(pb_endTurn);
    window->setLayout(outer);
    window->show();

    //TODO: Timer.
    return window;
}
