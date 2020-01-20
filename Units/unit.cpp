#include "unit.h"
#include <QPainter>

Unit::Unit(int HP,int AP,int initiative,int row,int col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent)
    : QGraphicsItem(parent)
    , m_max_HP(HP)
    , m_max_AP(AP)
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
    //TODO: z depth?
    //TODO: get setPos parameters from a source for both unit and field:

    //int m_field_width = 40;
    //int m_field_height = 40;
    //auto pos = m_gController->calculatePos(position());
    //this->setPos(pos.first, pos.second);
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
    //TODO: m_width...
    int m_width = 30;
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
    QPen pen(Qt::black, 3);
    painter->setPen(pen);
    painter->fillPath(path, m_color);
    painter->drawPath(path);
}


std::pair<int, int> Unit::position() const
{
    return std::pair(m_row, m_col);
}


std::pair<int, int> Unit::health() const
{
    return std::pair(m_remaining_HP, m_max_HP);
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


std::string Unit::info() const
{
    return "Unit says hello!\n"
            "Id: " + std::to_string(getId()) + "; "
            "Health: (" + std::to_string(health().first) + '/' + std::to_string(health().second) + ");";
}


std::ostream& operator<<(std::ostream& out, const Unit& u)
{
    return out << u.info();
}


std::vector<Action*>* Unit::getActions()
{
    return m_actions;
}


void Unit::setActions(std::vector<Action*>* newActions)
{
    m_actions = newActions;
}


/*void Unit::setPos(std::pair<qreal,qreal> position)
{
    QGraphicsItem::setPos(position.first, position.second);
}*/


/*void Unit::setController(GameController* gc)
{
    m_gController = gc;
}*/


/*bool Unit::move(std::pair<int,int> field){
    if () {
        //TODO: Some checks?
        // subtract action points used for moving? (In action class?)
        return true;
    }
    else {
        return false;
    }
}*/
