#include "field.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

Field::Field(unsigned row, unsigned col, int w, int h, QGraphicsItem* parent, QLabel* showInfo)
    //: QObject(nullptr)
    : QGraphicsItem(parent)
    , m_row(row)
    , m_col(col)
    , m_width(w)
    , m_height(h)
    , m_unit(nullptr)
    , m_color(Qt::white) // (int R, int G, int B)?
    , m_showInfo(showInfo)
{
    if (m_showInfo)
    {
        //TODO
        //QObject::connect(this, SIGNAL(LeftClicked()), m_showInfo, SLOT(setText("Left clicked!")));
    }
}


QRectF Field::boundingRect() const
{
    //TODO: qreal penWidth...
    return QRectF(-(m_width/2), -(m_height/2)
                  , m_width, m_height);
}

void Field::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)

    //TODO: Make a nice rectangle.
    /*painter->setBrush(m_color);
    painter->drawRect(-(m_width/2), -(m_height/2)
                      , m_width, m_height);*/
    QPainterPath path;
    path.addRect(-(m_width/2), -(m_height/2)
                 , m_width, m_height);
    QPen pen(Qt::black, 3);
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
    if(event->button() == Qt::LeftButton)
    {
        if (m_showInfo)
        {
            emit LeftClicked();
            std::cerr << "Left click on field: \n" << *this << std::endl;
        }
        else {
            std::cerr << "not connected!" << std::endl;
        }
    }
    if(event->button() == Qt::RightButton)
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
