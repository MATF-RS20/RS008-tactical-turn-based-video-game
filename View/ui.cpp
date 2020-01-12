#include "ui.h"
#include "QString"


std::pair<QWidget*, QGraphicsScene*> makeUI()
{
    QWidget* window = new QWidget();

    QGraphicsScene* scene = new QGraphicsScene(window);
    scene->setSceneRect(-200, -200, 400, 400);

    QGraphicsView* view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    //view->setWindowTitle("Game-view");
    view->resize(600, 600);

    QVBoxLayout* outerLayout = new QVBoxLayout();
    QHBoxLayout* actionsLayout = new QHBoxLayout();

    //TODO: Implement delete for actionButtons vector (vector only)
    std::vector<QPushButton*> * actionButtons = new std::vector<QPushButton*>();
    for (int i = 0; i < 10; i++)
    {
        QString actionName = "Action #"; //QString("Action #" + std::to_string(i));
        QPushButton* pb_tmp = new QPushButton(actionName, window);
        actionButtons->push_back(pb_tmp);
        actionsLayout->addWidget(pb_tmp);
    }

    QPushButton* pb_endTurn = new QPushButton("End turn", window);
    actionsLayout->addWidget(pb_endTurn);

    //actionsLayout->add

    outerLayout->addWidget(view);
    outerLayout->addLayout(actionsLayout);

    window->setLayout(outerLayout);
    window->setWindowTitle("The Game");
    window->resize(800, 800);

    return {window, scene};
}
