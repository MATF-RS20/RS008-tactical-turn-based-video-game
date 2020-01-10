#include "grid.h"
#include "field.h"


Grid::Grid(unsigned number_of_rows, unsigned number_of_cols)
    : m_row_size(number_of_rows), m_col_size(number_of_cols)
{
    _matrix = std::vector<std::vector<Field*>>();
    for (unsigned i = 0; i < m_row_size; i++)
    {
        std::vector<Field*> col = std::vector<Field*>();
        for (unsigned j = 0; j < m_col_size; j++)
        {
            Field* f = new Field(i, j);
            //f->setPos(0, 0);
            //TODO! : add fields with respect to position...
            col.push_back(f);
        }
        _matrix.push_back(col);
    }
}


std::pair<unsigned,unsigned> Grid::size() const
{
    return {m_row_size, m_col_size};
}


std::vector<std::vector<Field*>> Grid::matrix() const
{
    return _matrix;
}


std::ostream& operator<<(std::ostream& out, const Grid& g)
{
    unsigned number_of_rows, number_of_cols;
    std::tie(number_of_rows, number_of_cols) = g.size();

    out << "Grid matrix output start:\n";
    for (unsigned i = 0; i < number_of_rows; i++)
    {
        out << "  ";
        for (unsigned j = 0; j < number_of_cols; j++) {
            auto field = g.matrix()[i][j];
            out << field << ", ";
        }
        out << ";\n";
    }
    out << "End of grid matrix output.";
    return out;
}
