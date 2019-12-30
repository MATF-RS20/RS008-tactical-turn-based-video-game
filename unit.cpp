#include "unit.h"

Unit::Unit(int HP,int AP,int initiative,int row,int col)
    : _max_HP(HP), _max_AP(AP), _initiative(initiative), _row(row), _col(col)
{
    _remaining_HP = _max_HP;
    _remaining_AP = _max_AP;
}

std::pair<int, int> Unit::position() const
{
    return std::pair(_row, _col);
}

std::pair<int, int> Unit::health() const
{
    return std::pair(_remaining_HP,_max_HP);
}


void Unit::updateHealth(int change)
{
    int new_HP = _remaining_HP + change;
    if(new_HP > _max_HP) {
        new_HP = _max_HP;
    }
    else if(new_HP < 0) {
        //TODO: kill unit.
        new_HP = 0;
    }
    _remaining_HP = new_HP;
}


std::ostream& operator<<(std::ostream& out, const Unit& value)
{
    return out << "Unit says hello! It's health is: " << value.health().first << '/' << value.health().second << std::endl;
}








Warrior::Warrior(int HP, int AP, int initiative, int row, int col)
    : Unit(HP, AP, initiative, row, col)
{
    std::cerr<< "warrior constructor called"<< std::endl;
}

Warrior::~Warrior()
{
    std::cerr<< "warrior destructor called"<< std::endl;
}

std::ostream& operator<<(std::ostream& out, const Warrior& value)
{
    return out<< "warrior says hello!!"<< std::endl;
}





Healer::Healer(int HP, int AP, int initiative, int row, int col)
    : Unit(HP, AP, initiative, row, col)
{
    std::cerr<< "healer constructor called"<< std::endl;
}


Healer::~Healer()
{
    std::cerr<< "healer destructor called"<< std::endl;
}

std::ostream& operator<<(std::ostream& out, const Healer& value)
{
    return out<< "healer says hello!!"<< std::endl;
}
