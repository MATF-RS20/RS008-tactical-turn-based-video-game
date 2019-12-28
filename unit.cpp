#include "unit.h"

Unit::Unit(int HP,int AP,int initiative,int row,int col)
    : _HP(HP), _AP(AP), _initiative(initiative), _row(row), _col(col)
{

}
/*
int Unit::HP() const
int AP() const;
int initiative() const;
int row() const;
int col() const;
*/

std::ostream& operator<<(std::ostream& out, const Unit& value)
{
    return out << "Unit says hello!!" << std::endl;
}

Warrior::Warrior(int HP, int AP, int initiative, int row, int col)
    :Unit( HP, AP, initiative, row, col)
{
    std::cerr<< "warrior constructor called"<< std::endl;
}

std::ostream& operator<<(std::ostream& out, const Warrior& value)
{
    return out<< "warrior says hello!!"<< std::endl;
}

Warrior::~Warrior()
{
    std::cerr<< "warrior destructor called"<< std::endl;
}
