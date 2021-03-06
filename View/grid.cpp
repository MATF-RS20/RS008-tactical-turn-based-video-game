#include "grid.h"
#include "field.h"

Grid::Grid(unsigned number_of_rows, unsigned number_of_cols
           , unsigned field_width, unsigned field_height
           , QGraphicsItem* parent)
    : QGraphicsItem(parent)
    , m_row_size(number_of_rows)
    , m_col_size(number_of_cols)
    , m_field_width(field_width)
    , m_field_height(field_height)
    , m_signaler(new Signaler())
{
    m_matrix = std::vector<std::vector<Field*>>();
    for (unsigned i = 0; i < m_row_size; i++)
    {
        std::vector<Field*> col = std::vector<Field*>();
        for (unsigned j = 0; j < m_col_size; j++)
        {
            Field* f = new Field(i, j, m_signaler, m_field_width, m_field_height, this);
            f->setPos(j * m_field_width,
                      i * m_field_height);
            col.push_back(f);
        }
        m_matrix.push_back(col);
    }
}


QRectF Grid::boundingRect() const
{
    qreal w = m_field_width * m_col_size,
          h = m_field_height * m_row_size;
    return QRectF(-(w/2), -(h/2), w, h);
}


void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    return;
}

Grid::~Grid()
{
    //TODO: See if any double deleted.
    //check if qgraphics item parent deletes children
    /*for (auto col : m_matrix)
    {
        for (auto field : col)
        {
            if (field)
                delete field;
        }
        col.clear();
    }
    m_matrix.clear();*/
}


std::pair<unsigned,unsigned> Grid::size() const
{
    return {m_row_size, m_col_size};
}


/*std::vector<std::vector<Field*>> Grid::matrix() const
{
    return m_matrix;
}*/


bool Grid::validField(position_t position) const
{
    unsigned row, col;
    std::tie(row, col) = position;
    if (row >= m_row_size || col >= m_col_size)
    {
        return false;
    }
    else {
        return true;
    }
}


Field* Grid::at(position_t position) const
{
    if (validField(position))
    {
        return m_matrix[position.first][position.second];
    }
    return nullptr;
}


Field* Grid::operator[] (position_t position) const
{
    return at(position);
}


bool Grid::placeUnit(position_t field_position, Unit* unit)
{
    Field* f = at(field_position);
    if (f)
    {
        return f->placeUnit(unit);
    }
    return false;
}


void Grid::removeUnit(position_t field_position)
{
    Field* f = at(field_position);
    if (f) {
        f->removeUnit();
    }
}


Signaler* Grid::signaler() const
{
    return m_signaler;
}
