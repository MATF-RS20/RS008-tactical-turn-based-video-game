#ifndef FIELD_H
#define FIELD_H

#include <iostream>

class Field
{
public:
    Field(int row, int col);

    //getters
    int row() const;
    int col() const;

private:
    int _row,
        _col;
};

std::ostream& operator<<(std::ostream& out, const Field& value);

#endif // FIELD_H
