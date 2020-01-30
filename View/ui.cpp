#include "ui.h"

#include <QString>
#include <QVBoxLayout>
#include <QGraphicsView>

#define MAX_NUMBER_OF_ACTION_BUTTONS 10

ui makeUI()
{
    QWidget* window = new QWidget();

    QVBoxLayout* layoutV_outer = new QVBoxLayout();
        //QHBoxLayout* layoutH_unitsQueue = new QHBoxLayout();
        QHBoxLayout* layoutH_main = new QHBoxLayout();
        QHBoxLayout* layoutH_actions = new QHBoxLayout();


    //<UNITS-QUEUE>
        //TODO: unitsQueue
    //</UNITS-QUEUE>


    //<MAIN>
        //<MAIN-RIGHT>
            //TODO: set fixed width for showInfo
            QVBoxLayout* layoutV_mainRight = new QVBoxLayout();

            QLabel* currentPlayer = new QLabel("TODO: Set Player");
            //TODO: set color based on player.
            //currentPlayer->setStyleSheet("QLabel { background-color : red; color : blue; }");
            currentPlayer->setWordWrap(true);
            currentPlayer->setFixedSize(200,50);

            QLabel* showInfo = new QLabel("Hello");
            showInfo->setWordWrap(true);
            showInfo->setFixedWidth(200);

            //<BOTTOM-OK_CANCEL>
                QPushButton* pb_ok = new QPushButton("Ok", window);
                pb_ok->setEnabled(false);
                QPushButton* pb_cancel = new QPushButton("Cancel", window);
                pb_cancel->setEnabled(false);
                QHBoxLayout* mainRight_footer = new QHBoxLayout();
                mainRight_footer->addWidget(pb_ok);
                mainRight_footer->addWidget(pb_cancel);
            //</BOTTOM-OK_CANCEL>

            layoutV_mainRight->addWidget(currentPlayer);
            layoutV_mainRight->addWidget(showInfo);
            layoutV_mainRight->addLayout(mainRight_footer);
        //</MAIN-RIGHT>


        //<VIEW>
            QGraphicsScene* scene = new QGraphicsScene(window);
            scene->setSceneRect(-200, -200, 400, 400);

            QGraphicsView* view = new QGraphicsView(scene);
            view->setRenderHint(QPainter::Antialiasing);
            view->setDragMode(QGraphicsView::ScrollHandDrag);
            view->resize(600, 600);
        //</VIEW>


        layoutH_main->addWidget(view);
        layoutH_main->addLayout(layoutV_mainRight);
    //</MAIN>


    //<ACTIONS>
        std::vector<ActionButton*> actionButtons = std::vector<ActionButton*>();
        for (unsigned i = 0; i < MAX_NUMBER_OF_ACTION_BUTTONS; i++)
        {
            ActionButton* pb_tmp = new ActionButton(i, window);
            actionButtons.push_back(pb_tmp);
            layoutH_actions->addWidget(pb_tmp);
        }

        QPushButton* pb_endTurn = new QPushButton("End turn", window);
        layoutH_actions->addWidget(pb_endTurn);
    //</ACTIONS>


    //layoutV_outer->addLayout(layoutH_unitsQueue);
    layoutV_outer->addLayout(layoutH_main);
    layoutV_outer->addLayout(layoutH_actions);

    window->setLayout(layoutV_outer);
    window->setWindowTitle("The Game");
    window->resize(800, 800);

    return {window, scene, showInfo, currentPlayer, actionButtons, pb_ok, pb_cancel, pb_endTurn};
}
