#ifndef UI_H
#define UI_H

#include "field.h"
#include "grid.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>


struct ui {
    QWidget* window;
    QGraphicsScene* scene;
    QLabel* showInfo;
    std::vector<QPushButton*> * actionButtons;
    QPushButton* pb_endTurn;
};


ui makeUI();


#endif // UI_H
