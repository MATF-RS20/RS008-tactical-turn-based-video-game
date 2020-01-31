#include "unit.h"
#include <QPainter>

Warrior::Warrior(int HP, int AP, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent)
    : Unit(HP, AP, initiative, row, col, player, actions, parent)
{
    //std::cerr<< "warrior constructor called"<< std::endl;
}


Warrior::~Warrior()
{
    //std::cerr<< "warrior destructor called"<< std::endl;
}


std::string Warrior::unitClass() const
{
    return "Warrior";
}


std::ostream& operator<<(std::ostream& out, const Warrior& warrior)
{
    return out << warrior.info();
}

void Warrior::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)
    int m_width = 30;
    int m_height = 30;

    QPainterPath path;
    path.addEllipse(-(m_width/2), -(m_height/2)
                 , m_width, m_height);
    QPen pen(Qt::black, 2);
    painter->setPen(pen);
    painter->fillPath(path, m_color);
    painter->drawPath(path);
    painter->drawText(QRectF(-(m_width/2), -(m_height/2)
                             , m_width, m_height), Qt::AlignHCenter, "w");
}
