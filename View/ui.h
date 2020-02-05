#ifndef UI_H
#define UI_H

#include "field.h"
#include "grid.h"
#include "actionbutton.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsView>
#include <QMouseEvent>



class myView : public QGraphicsView
{
    Q_OBJECT

public:
    myView(QGraphicsScene* scene) : QGraphicsView(scene) {}

    void mousePressEvent(QMouseEvent* event) override;

signals:
    void clicked();
};


struct ui {
    QWidget* window;
    QGraphicsScene* scene;
    myView* view;
    QLabel* showInfo;
    QLabel* playerLabel;
    std::vector<ActionButton*> actionButtons; //Vector deleted in the game controller constructor.
    QPushButton* pb_ok;
    QPushButton* pb_cancel;
    QPushButton* pb_endTurn;
};

ui makeUI();


#endif // UI_H
