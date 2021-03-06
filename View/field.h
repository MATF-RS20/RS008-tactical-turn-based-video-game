#ifndef FIELD_H
#define FIELD_H

#include "Model/type_definitions.h"
#include "Model/Units/unit.h"
#include "Controller/signaler.h"

#include <QGraphicsItem>
#include <QLabel>
#include <iostream>

#define DEFAULT_FIELD_COLOR Qt::white


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

    void setColor(QColor new_color);
    void setColor();

    bool placeUnit(Unit* u);
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
