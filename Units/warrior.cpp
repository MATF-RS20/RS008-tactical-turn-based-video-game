#include "unit.h"


Warrior::Warrior(int HP, int AP, int initiative, int row, int col, std::vector<Action>* actions, QGraphicsItem* parent)
    : Unit(HP, AP, initiative, row, col, actions, parent)
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
            "Id: " + std::to_string(getId()) + "; "
            "Health: " + std::to_string(health().first) + '/' + std::to_string(health().second) + ";\n";
}
