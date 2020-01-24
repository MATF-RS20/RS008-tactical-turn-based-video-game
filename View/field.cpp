#include "field.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#define MAX_WIDTH  100
#define MAX_HEIGHT 100

Field::Field(unsigned row, unsigned col, unsigned w, unsigned h, QGraphicsItem* parent)
    //: QObject(nullptr)
    : QGraphicsItem(parent)
    , m_row(row)
    , m_col(col)
    , m_width (w < MAX_WIDTH ? w : MAX_WIDTH)
    , m_height(h < MAX_HEIGHT ? h : MAX_HEIGHT)
    , m_unit(nullptr)
    , m_color(Qt::white) // (int R, int G, int B)?
{}


QRectF Field::boundingRect() const
{
    //TODO: qreal penWidth...
    qreal w = m_width,
          h = m_height;
    return QRectF(-(w/2), -(h/2)
                  , w, h);
}

void Field::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)
    qreal w = m_width,
          h = m_height;

    QPainterPath path;
    path.addRect(-(w/2), -(h/2), w, h);

    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    painter->fillPath(path, m_color);
    painter->drawPath(path);
}


Field* Field::LeftClicked()
{
    return this;
}


void Field::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if (event->button() == Qt::LeftButton)
    {
        // TODO: emit LeftClicked() -> emit wrapper(this) -> gc
        //emit LeftClicked();
        //std::cerr << "Left click on field: \n" << *this << std::endl;
    }

    if (event->button() == Qt::RightButton)
    {
        std::cerr << "Right click on field: ("
                  << m_row << ", " << m_col << ")" << std::endl;
    }
}


unsigned Field::row() const
{
    return m_row;
}


unsigned Field::col() const
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


void Field::placeUnit(Unit* u)
{
    m_unit = u;
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
