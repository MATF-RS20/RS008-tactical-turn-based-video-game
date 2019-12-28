#ifndef GRID_H
#define GRID_H

#include "field.h"
#include <iostream>
#include <vector>


class Grid
{
public:
    Grid(int row_number, int col_number);

    //getters
    int row_number() const;
    int col_number() const;
    std::vector<std::vector<Field>> matrix() const;


private:
    int _row_number,
        _col_number;
    std::vector<std::vector<Field>> _matrix;
};

std::ostream& operator<<(std::ostream& out, const Grid& value);

#endif // GRID_H
