#include "grid.h"

Grid::Grid(int col_number, int row_number)
    : _col_number(col_number), _row_number(row_number)
{}

int Grid::col_number() const
{
    return _col_number;
}

int Grid::row_number() const
{
    return _row_number;
}

std::ostream& operator<<(std::ostream& out, const Grid& value)
{
    return out << "Number of columns is: " << value.col_number() << ";Number of rows is: " << value.row_number();
}
