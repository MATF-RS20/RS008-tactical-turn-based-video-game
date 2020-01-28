#ifndef FIELD_H
#define FIELD_H

#include "type_definitions.h"
#include "Units/unit.h"
#include "Controller/signaler.h"

#include <QGraphicsItem>
#include <QLabel>
#include <iostream>



class Field : public QGraphicsItem
{

public:
    Field(unsigned row, unsigned col, Signaler* signaler, unsigned w = 40, unsigned h = 40, QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;


    position_t position() const; //row, col
    Unit* unit() const;
    std::string info() const;

    void placeUnit(Unit* u);
    void removeUnit();

private:
    const unsigned
        m_row,
        m_col;
    paintSize_t
        m_width,
        m_height;
    Unit* m_unit;
    QColor m_color;
    Signaler* m_signaler;
};

std::ostream& operator<<(std::ostream& out, const Field& value);

#endif // FIELD_H
