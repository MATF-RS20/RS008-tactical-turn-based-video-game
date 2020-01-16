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
    QLabel* showInfo = new QLabel("Hello");
    showInfo->setWordWrap(true);
    showInfo->setFixedWidth(150);
    //QObject::connect()


    layoutH_main->addWidget(view);
    layoutH_main->addWidget(showInfo);

    //TODO: Implement delete for actionButtons vector (vector only)
    std::vector<QPushButton*> * actionButtons = new std::vector<QPushButton*>();
    for (int i = 0; i < 10; i++)
    {
        char const * actionName = std::string("Action " + std::to_string(i)).c_str();
        QPushButton* pb_tmp = new QPushButton(actionName, window);
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

    return {window, scene, showInfo, actionButtons, pb_endTurn};
}
