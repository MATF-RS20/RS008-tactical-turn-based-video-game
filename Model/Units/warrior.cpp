#include "unit.h"
#include <QPainter>

Warrior::Warrior(int HP, int AP, int AP_regen, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent)
    : Unit(HP, AP, AP_regen, initiative, row, col, player, actions, parent)
{
    //std::cerr<< "warrior constructor called"<< std::endl;
}

Warrior::Warrior(unsigned row, unsigned col, Player* player)
    :Warrior(
         300, 8, 5, 5 //HP, AP, AP regen, intiative
         , row, col, player
         , new std::vector<Action*>({new Action("Move", ActionType::move, 0, 2), new Action("Attack", ActionType::damage, 40, 3)})
         , nullptr // player
         )
{}


Warrior::~Warrior()
{
    //std::cerr<< "warrior destructor called"<< std::endl;

    //TODO: make sure nothing is double deleted.
    //TODO: make a different action representation.
    for (auto e: *m_actions) {
        delete e;
    }
    //m_actions->clear();
    delete m_actions;
}


std::string Warrior::unitClass() const
{
    return "Warrior";
}


void Warrior::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Unit::paintWithText("w", painter, option, widget);
}


std::ostream& operator<<(std::ostream& out, const Warrior& warrior)
{
    return out << warrior.info();
}
