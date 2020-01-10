#ifndef FIELD_H
#define FIELD_H

#include "Units/unit.h"

#include <QGraphicsItem>
#include <iostream>

class Field : public QGraphicsItem
{
public:
    Field(int row, int col);

    // Okvir polja, za ponovno isrtavanje.
    QRectF boundingRect() const override;

    //QPainterPath shape() const override;
    void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget) override;

    //TODO: Show info on mouse click.
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

    //getters
    int row() const;
    int col() const;
    std::pair<int, int> position() const;
    Unit* unit() const;

    bool hasUnit() const;
    void placeUnit(Unit u);
    void removeUnit();

private:
    const int m_row,
        m_col;
    Unit* m_unit;
    qreal m_width;
    qreal m_height;
    QColor m_color;
};

std::ostream& operator<<(std::ostream& out, const Field& value);

#endif // FIELD_H
