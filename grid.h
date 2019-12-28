#ifndef GRID_H
#define GRID_H
#include<iostream>


class Grid
{
public:
    Grid(int col_number, int row_number);

    //getters
    int col_number() const;
    int row_number() const;


private:
    int _col_number,
        _row_number;
};

std::ostream& operator<<(std::ostream& out, const Grid& value);

#endif // GRID_H
