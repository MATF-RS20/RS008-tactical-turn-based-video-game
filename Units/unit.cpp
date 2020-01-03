#include "unit.h"

Unit::Unit(int HP,int AP,int initiative,int row,int col)
    : m_max_HP(HP), m_max_AP(AP), m_initiative(initiative), m_row(row), m_col(col)
{
    setId();
    m_remaining_HP = m_max_HP;
    m_remaining_AP = m_max_AP;
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


std::ostream& operator<<(std::ostream& out, const Unit& u)
{
    return out << "Unit says hello!\n"
               << "Id: " << u.getId() << "; "
               << "Health: " << u.health().first << '/' << u.health().second << ";";

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

std::ostream& operator<<(std::ostream& out, const Warrior& w)
{
    return out<< "warrior id=" << w.getId() <<" says hello!!"<< std::endl;
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
