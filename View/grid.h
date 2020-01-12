#ifndef GRID_H
#define GRID_H

#include "field.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <iostream>
#include <vector>


class Grid : public QGraphicsItem
{
public:
    Grid(unsigned number_of_rows, unsigned number_of_cols, QGraphicsItem* parent = nullptr);

    //~Grid() override;

    QRectF boundingRect() const override;

    //QPainterPath shape() const override;
    void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget) override;

    std::pair<unsigned,unsigned> size() const;
    std::vector<std::vector<Field*>> matrix() const;


private:
    unsigned m_row_size,
             m_col_size;
    std::vector<std::vector<Field*>> m_matrix;
    int m_field_width = 40,
        m_field_height = 40;
};

std::ostream& operator<<(std::ostream& out, const Grid& value);

#endif // GRID_H
