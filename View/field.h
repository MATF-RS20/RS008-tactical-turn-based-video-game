#ifndef FIELD_H
#define FIELD_H

#include "Units/unit.h"

#include <QGraphicsItem>
#include <QLabel>
#include <iostream>

class Field : public QGraphicsItem
{
    //Q_OBJECT

public:
    Field(unsigned row, unsigned col, unsigned w = 40, unsigned h = 40, QGraphicsItem* parent = nullptr);

    // Okvir polja, za ponovno isrtavanje.
    QRectF boundingRect() const override;

    //QPainterPath shape() const override;
    void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget) override;

    //TODO: Show info on mouse click.
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

    //getters
    unsigned row() const;
    unsigned col() const;
    std::pair<int, int> position() const;
    Unit* unit() const;

    bool hasUnit() const;
    void placeUnit(Unit* u);
    void removeUnit();

signals:
    Field* LeftClicked();

private:
    const unsigned
        m_row,
        m_col,
        m_width,
        m_height;
    Unit* m_unit;
    QColor m_color;
};

std::ostream& operator<<(std::ostream& out, const Field& value);

#endif // FIELD_H
