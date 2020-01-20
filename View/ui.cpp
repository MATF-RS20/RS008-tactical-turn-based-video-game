#include "ui.h"
#include "QString"

ui makeUI()
{
    QWidget* window = new QWidget();

    QGraphicsScene* scene = new QGraphicsScene(window);
    scene->setSceneRect(-200, -200, 400, 400);

    QGraphicsView* view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->resize(600, 600);

    QVBoxLayout* layoutV_outer = new QVBoxLayout();

    //QHBoxLayout* layoutH_unitsQueue = new QHBoxLayout();
    QHBoxLayout* layoutH_main = new QHBoxLayout();
    QHBoxLayout* layoutH_actions = new QHBoxLayout();


    //TODO: unitsQueue


    //TODO: set fixed width for showInfo
    QVBoxLayout* layoutV_mainRight = new QVBoxLayout();

    QLabel* currentPlayer = new QLabel("TODO: Set Player");
    //TODO: set color based on player.
    //currentPlayer->setStyleSheet("QLabel { background-color : red; color : blue; }");
    currentPlayer->setWordWrap(true);
    currentPlayer->setFixedSize(150,50);

    QLabel* showInfo = new QLabel("Hello");
    showInfo->setWordWrap(true);
    showInfo->setFixedWidth(150);

    layoutV_mainRight->addWidget(currentPlayer);
    layoutV_mainRight->addWidget(showInfo);


    layoutH_main->addWidget(view);
    layoutH_main->addLayout(layoutV_mainRight);

    //TODO: Delete this vector when deleting window? After adding to gc?
    std::vector<ActionButton*> * actionButtons = new std::vector<ActionButton*>();
    for (int i = 0; i < 10; i++)
    {
        ActionButton* pb_tmp = new ActionButton(i, window);
        //TODO: add signals and slots!
        actionButtons->push_back(pb_tmp);
        layoutH_actions->addWidget(pb_tmp);
    }

    QPushButton* pb_endTurn = new QPushButton("End turn", window);
    layoutH_actions->addWidget(pb_endTurn);

    //layoutH_actions->addLayout(layoutH_unitsQueue);
    layoutV_outer->addLayout(layoutH_main);
    layoutV_outer->addLayout(layoutH_actions);

    window->setLayout(layoutV_outer);
    window->setWindowTitle("The Game");
    window->resize(800, 800);

    return {window, scene, showInfo, currentPlayer, actionButtons, pb_endTurn};
}
