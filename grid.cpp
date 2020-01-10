#include "grid.h"
#include "field.h"

Grid::Grid(int row_number, int col_number)
    : _row_number(row_number), _col_number(col_number)
{
    _matrix = std::vector<std::vector<Field*>>();
    for (int i = 0; i < _row_number; i++)
    {
        std::vector<Field*> col = std::vector<Field*>();
        for (int j = 0; j < _col_number; j++)
        {
            Field* f = new Field(i, j);
            //f->setPos(0, 0);
            //TODO! : add fields with respect to position...
            col.push_back(f);
        }
        _matrix.push_back(col);
    }
}

int Grid::row_number() const
{
    return _row_number;
}

int Grid::col_number() const
{
    return _col_number;
}

std::vector<std::vector<Field*>> Grid::matrix() const
{
    return _matrix;
}

std::ostream& operator<<(std::ostream& out, const Grid& g)
{
    //return out << "Number of columns is: " << value.col_number() << ";Number of rows is: " << value.row_number();

    out << "Grid matrix output start:\n";
    for (int i = 0; i < g.row_number(); i++)
    {
        //auto row = value.matrix()[i];
        out << "  ";
        for (int j = 0; j < g.col_number(); j++) {
            auto field = g.matrix()[i][j];
            out << field << ", ";
        }
        out << ";\n";
    }
    out << "End of grid matrix output.";
    return out;
}
