#include "field.h"

Field::Field(int row, int col)
    : m_row(row), m_col(col)
{
    m_unit = nullptr;
}


int Field::row() const
{
    return m_row;
}


int Field::col() const
{
    return m_col;
}


std::pair<int, int> Field::position() const
{
    return std::pair(m_row, m_col);
}

Unit* Field::unit() const
{
    return m_unit;
}


bool Field::hasUnit() const
{
    return m_unit != nullptr;
}


void Field::placeUnit(Unit u)
{
    m_unit = &u;
}


void Field::removeUnit()
{
    m_unit = nullptr;
}


std::ostream& operator<<(std::ostream& out, const Field& f)
{
    if (f.hasUnit())
        return out << "Field: (" << f.row() << ", " << f.col() << "), with placed unit:\n"
                   << *(f.unit());
    else
        return out << "Empty field: (" << f.row() << ", " << f.col() << ")";
}
