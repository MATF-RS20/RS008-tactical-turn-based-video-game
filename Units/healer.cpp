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


std::string Healer::info() const
{
    return "Healer\n"
           "Id: " + std::to_string(m_id) + "\n"
           "Health: " + std::to_string(m_remaining_HP) + '/' + std::to_string(m_max_HP);
}


std::ostream& operator<<(std::ostream& out, const Healer& healer)
{
    return out << healer.info();
}
