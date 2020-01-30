#include "field.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#define MAX_WIDTH  100
#define MAX_HEIGHT 100


Field::Field(unsigned row, unsigned col, Signaler* signaler, unsigned w, unsigned h, QGraphicsItem* parent)
    //: QObject(nullptr)
    : QGraphicsItem(parent)
    , m_row(row)
    , m_col(col)
    , m_width (w < MAX_WIDTH ? w : MAX_WIDTH)
    , m_height(h < MAX_HEIGHT ? h : MAX_HEIGHT)
    , m_unit(nullptr)
    , m_color(Qt::white) // (int R, int G, int B)?
    , m_signaler(signaler)
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


void Field::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (m_signaler)
        m_signaler->fieldLeftClick(position());
    }

    if (event->button() == Qt::RightButton)
    {
        std::cerr << "Right click on field: ("
                  << m_row << ", " << m_col << ")" << std::endl;
    }
}


position_t Field::position() const
{
    return std::pair(m_row, m_col);
}


Unit* Field::unit() const
{
    return m_unit;
}


void Field::placeUnit(Unit* u)
{
    u->setParentItem(this);
    u->setPosition(position());
    m_unit = u;
}


void Field::removeUnit()
{
    m_unit = nullptr;
}


std::string Field::info() const
{
    if (m_unit)
        return "Field: (" + std::to_string(m_row) + ", "  + std::to_string(m_col) +  ")\n"
                + "Placed Unit:\n" + m_unit->info();
    else
        return "Field: (" + std::to_string(m_row) + ", "  + std::to_string(m_col) +  ")\n"
                + "No placed unit";
}


std::ostream& operator<<(std::ostream& out, const Field& field)
{
    return out << field.info();
}


std::ostream& operator<<(std::ostream& out, position_t position) {
    return out << "(" << position.first << "," << position.second << ")";
}


std::string to_string(position_t position)
{
    return "(" + std::to_string(position.first) + "," + std::to_string(position.second) + ")";
}
