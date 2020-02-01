#include "unit.h"
#include <QPainter>


Healer::Healer(int HP, int AP, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent)
    : Unit(HP, AP, initiative, row, col, player, actions, parent)
{
    //std::cerr<< "Healer constructor called"<< std::endl;
}

Healer::Healer(unsigned row, unsigned col, Player* player)
    :Unit(
         200, 8, 4
         , row, col, player
         , new std::vector<Action*>({new Action("Move", ActionType::move, 0, 2), new Action("Heal", ActionType::heal, 20, 2), new Action("Weak Attack", ActionType::damage, 20, 3)})
         )
{}


Healer::~Healer()
{
    //std::cerr<< "Healer destructor called"<< std::endl;
    for (auto e: *m_actions) { //TOOD: change vector of action pointers to vector of actions
        delete e;
    }
    //m_actions->clear();
    delete m_actions;
}


std::string Healer::unitClass() const
{
    return "Healer";
}


void Healer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Unit::paintWithText("h", painter, option, widget);
}


std::ostream& operator<<(std::ostream& out, const Healer& healer)
{
    return out << healer.info();
}
