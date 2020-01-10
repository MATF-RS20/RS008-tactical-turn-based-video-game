#ifndef GRID_H
#define GRID_H

#include "field.h"
#include <QGraphicsScene>
#include <iostream>
#include <vector>


class Grid
{
public:
    Grid(unsigned number_of_rows, unsigned number_of_cols, QGraphicsScene* scene);

    ~Grid();

    std::pair<unsigned,unsigned> size() const;
    std::vector<std::vector<Field*>> matrix() const;


private:
    unsigned m_row_size,
             m_col_size;
    std::vector<std::vector<Field*>> m_matrix;
};

std::ostream& operator<<(std::ostream& out, const Grid& value);

#endif // GRID_H
