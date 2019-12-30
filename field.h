#ifndef FIELD_H
#define FIELD_H

#include "Units/unit.h"

#include <iostream>

class Field
{
public:
    Field(int row, int col);

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
};

std::ostream& operator<<(std::ostream& out, const Field& value);

#endif // FIELD_H
