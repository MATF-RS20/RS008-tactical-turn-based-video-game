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


std::string Unit::info() const
{
    return "Unit says hello!\n"
            "Id: " + std::to_string(getId()) + "; "
            "Health: (" + std::to_string(health().first) + '/' + std::to_string(health().second) + ");";
}


std::ostream& operator<<(std::ostream& out, const Unit& u)
{
    return out << u.info();
}
