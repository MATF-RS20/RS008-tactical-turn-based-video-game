#ifndef LEVELS_H
#define LEVELS_H

#include "Controller/gamecontroller.h"
#include <QLabel>
#include <QPushButton>


GameController* createLevel1(QGraphicsScene* scene, QLabel* showInfo, QPushButton* pb_endTurn);


#endif // LEVELS_H
