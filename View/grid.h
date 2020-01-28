#ifndef GRID_H
#define GRID_H

#include "field.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <iostream>
#include <vector>
#include <Controller/signaler.h>


class Grid : public QGraphicsItem
{
public:
    Grid(unsigned number_of_rows, unsigned number_of_cols
         , unsigned field_width = 40, unsigned field_height = 40
         , QGraphicsItem* parent = nullptr);

    ~Grid() override;

    QRectF boundingRect() const override;

    //QPainterPath shape() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    bool validField(position_t position);
    Field* operator[] (position_t position);
    bool placeUnit(position_t field_position, Unit* unit);
    void removeUnit(position_t field_position);

    std::pair<unsigned,unsigned> size() const;
    std::vector<std::vector<Field*>> matrix() const;

    unsigned field_width() const {return m_field_width;}
    unsigned field_height() const {return m_field_height;}

    Signaler* signaler() const;

private:
    const unsigned
        m_row_size,
        m_col_size;
    paintSize_t
        m_field_width,
        m_field_height;
    std::vector<std::vector<Field*>> m_matrix;
    Signaler* m_signaler;
};

std::ostream& operator<<(std::ostream& out, const Grid& value);

#endif // GRID_H
