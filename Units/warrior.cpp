#include "unit.h"


Warrior::Warrior(int HP, int AP, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent)
    : Unit(HP, AP, initiative, row, col, player, actions, parent)
{
    //std::cerr<< "warrior constructor called"<< std::endl;
}


Warrior::~Warrior()
{
    //std::cerr<< "warrior destructor called"<< std::endl;
}


std::string Warrior::info() const
{
    return "Warrior\n"
           "Id: " + std::to_string(m_id) + "\n"
           "Health: " + std::to_string(m_remaining_HP) + '/' + std::to_string(m_max_HP);
}
