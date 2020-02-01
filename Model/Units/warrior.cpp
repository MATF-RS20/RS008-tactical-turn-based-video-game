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


void Warrior::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Unit::paintWithText("w", painter, option, widget);
}


std::ostream& operator<<(std::ostream& out, const Warrior& warrior)
{
    return out << warrior.info();
}
