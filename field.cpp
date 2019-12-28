#include "field.h"

Field::Field(int row, int col)
    : _row(row), _col(col)
{}

int Field::row() const
{
    return _row;
}

int Field::col() const
{
    return _col;
}

std::ostream& operator<<(std::ostream& out, const Field& value)
{
    return out << "Field: (" << value.row() << ", " << value.col() << ")";
}
