#ifndef UI_H
#define UI_H

#include "field.h"
#include "grid.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>


std::pair<QWidget*, QGraphicsScene*> makeUI();


#endif // UI_H
