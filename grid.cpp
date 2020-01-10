#include "grid.h"
#include "field.h"


Grid::Grid(unsigned number_of_rows, unsigned number_of_cols, QGraphicsScene* scene)
    : m_row_size(number_of_rows)
    , m_col_size(number_of_cols)
{
    qreal grid_left = 0, grid_top = 0;
    int field_a = 40;
    m_matrix = std::vector<std::vector<Field*>>();
    for (unsigned i = 0; i < m_row_size; i++)
    {
        std::vector<Field*> col = std::vector<Field*>();
        for (unsigned j = 0; j < m_col_size; j++)
        {
            Field* f = new Field(i, j, field_a);
            f->setPos(grid_left + j * field_a,
                      grid_top  + i * field_a);
            (*scene).addItem(f);
            col.push_back(f);
        }
        m_matrix.push_back(col);
    }
}


Grid::~Grid()
{
    //TODO: See if any double deleted.
    for (auto col : m_matrix)
    {
        for(auto field : col)
        {
            delete field;
        }
        col.clear();
    }
    m_matrix.clear();
}


std::pair<unsigned,unsigned> Grid::size() const
{
    return {m_row_size, m_col_size};
}


std::vector<std::vector<Field*>> Grid::matrix() const
{
    return m_matrix;
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
