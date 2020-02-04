#include "unit.h"
#include <QPainter>

Unit::Unit(int HP, int AP, int AP_regen, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent)
    : QGraphicsItem(parent)
    , m_max_HP(HP)
    , m_max_AP(AP)
    , m_AP_regen(AP_regen)
    , m_initiative(initiative)
    , m_row(row)
    , m_col(col)
    , m_actions(actions)
    , m_player(player)
{
    setId();
    m_remaining_HP = m_max_HP;
    m_remaining_AP = m_max_AP;

    m_color = m_player ? m_player->color() : Qt::black;
}


unsigned Unit::next_id = 0;


void Unit::setId()
{
    m_id = Unit::next_id++;
}


unsigned Unit::getId() const
{
    return m_id;
}


QRectF Unit::boundingRect() const
{
    int m_width = 30; //TODO: get dimensions from external source?
    int m_height = 30;
    return QRectF(-(m_width/2), -(m_height/2)
                  , m_width, m_height);
}

void Unit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)
    int m_width = 30;
    int m_height = 30;
    /*QColor m_color = QColor(Qt::black);
    if (!m_player)
    {
        QColor m_color = QColor(Qt::black);
        std::cerr << "Error: player=nullptr in unit::paint" << std::endl;
    }*/

    QPainterPath path;
    path.addEllipse(-(m_width/2), -(m_height/2)
                 , m_width, m_height);
    QPen pen(m_outline_color, 3);
    painter->setPen(pen);
    painter->fillPath(path, m_color);
    painter->drawPath(path);
}


void Unit::paintWithText(QString text, QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Unit::paint(painter, option, widget);

    int m_width = 40;
    int m_height = 40; //TODO: define w & height relative to field. Get(set) somehow.
    QPen pen(Qt::black, 2);
    painter->setPen(pen);
    painter->drawText(QRectF(-(m_width/2), -(m_height/2)
                             , m_width, m_height), Qt::AlignHCenter | Qt::AlignVCenter, text);
}


position_t Unit::position() const
{
    return std::pair(m_row, m_col);
}


AP_cost_t Unit::AP_left() const
{
    return static_cast<AP_cost_t>(m_remaining_AP);
}


int Unit::HP_left() const
{
    return m_remaining_HP;
}


void Unit::updateHealth(int change)
{
    int new_HP = m_remaining_HP + change;
    if(new_HP > m_max_HP) {
        new_HP = m_max_HP;
    }
    else if(new_HP < 0) {
        //TODO: kill unit.
        new_HP = 0;
    }
    m_remaining_HP = new_HP;
}


void Unit::updateHealth(unsigned change)
{
    updateHealth(static_cast<int>(change));
}


void Unit::updateAP(int change)
{
    //std::cerr << "Update AP" << std::endl;
    int new_AP = m_remaining_AP + change;
    new_AP = new_AP > m_max_AP ? m_max_AP : new_AP;
    new_AP = new_AP < 0 ? 0 : new_AP;

    m_remaining_AP = new_AP;
}


void Unit::regenAP()
{
    updateAP(m_AP_regen);
}


std::string Unit::info() const
{
    return unitClass() + "\n"
    "Id: " + std::to_string(m_id) + "\n"
    "Position: " + to_string(position()) + "\n"
    "Health: " + std::to_string(m_remaining_HP) + '/' + std::to_string(m_max_HP) + "\n"
    "Action Points: " + std::to_string(m_remaining_AP) + '/' + std::to_string(m_max_AP);
}


std::string Unit::unitClass() const
{
    return "Base Unit";
}


std::vector<Action*>* Unit::getActions()
{
    return m_actions;
}


void Unit::setActions(std::vector<Action*>* newActions)
{
    m_actions = newActions;
}


void Unit::changeColor(QColor color)
{
    m_color = color;
}


void Unit::changeColor()
{
    m_color = m_player->color();
}


void Unit::highlight()
{
    m_outline_color = DEFAULT_HIGHLIGHT_COLOR;
}


void Unit::unHighlight()
{
    m_outline_color = DEFAULT_OUTLINE_COLOR;
}


Player* Unit::player()
{
    return m_player;
}

void Unit::setPosition(position_t new_position)
{
    m_row = new_position.first;
    m_col = new_position.second;
}


unsigned Unit::id()
{
    return m_id;
}


bool Unit::operator==(Unit& other)
{
    return m_id == other.id();
}


bool Unit::operator!=(Unit& other)
{
    return !(*this == other);
}


bool Unit::operator<(Unit& other)
{
    return this->m_initiative < other.m_initiative;
}


std::ostream& operator<<(std::ostream& out, const Unit& u)
{
    return out << u.info();
}
