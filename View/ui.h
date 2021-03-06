#ifndef UI_H
#define UI_H

#include "field.h"
#include "grid.h"
#include "actionbutton.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QLabel>
#include <QPushButton>


struct ui {
    QWidget* window;
    QGraphicsScene* scene;
    QLabel* showInfo;
    QLabel* playerLabel;
    std::vector<ActionButton*> actionButtons; //Vector deleted in the game controller constructor.
    QPushButton* pb_ok;
    QPushButton* pb_cancel;
    QPushButton* pb_endTurn;
};


ui makeUI();


#endif // UI_H
