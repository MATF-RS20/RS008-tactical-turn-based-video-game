#include "unit.h"


Healer::Healer(int HP, int AP, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent)
    : Unit(HP, AP, initiative, row, col, player, actions, parent)
{
    //std::cerr<< "Healer constructor called"<< std::endl;
}


Healer::~Healer()
{
    //std::cerr<< "Healer destructor called"<< std::endl;
}


std::string Healer::unitClass() const
{
    return "Healer";
}


std::ostream& operator<<(std::ostream& out, const Healer& healer)
{
    return out << healer.info();
}
