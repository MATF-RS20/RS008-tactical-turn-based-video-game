#ifndef UNIT_H
#define UNIT_H

#include "Actions/action.h"
#include "player.h"

#include <iostream>
#include <vector>

class Unit
{
public:
    virtual ~Unit() = default;

    //virtual Unit * Copy() const = 0;

    std::pair<int,int> position() const;
    std::pair<int, int> health() const;
    void updateHealth(int change);
    unsigned getId() const;
    virtual std::string info() const;

protected:
    Unit(int HP, int AP, int initiative, int row, int col);
    void setId();

    //HealthPoints, ActionPoints
    int m_max_HP,
        m_remaining_HP,
        m_max_AP,
        m_remaining_AP,
        m_initiative,
        m_row,
        m_col;
    unsigned m_id;
    static unsigned next_id;
    std::vector<Action>* m_actions;
    Player* m_player;
};

std::ostream& operator<<(std::ostream& out, const Unit& value);









class Warrior: public Unit
{
public:
    Warrior(int HP, int AP, int initiative, int row, int col);

    ~Warrior();

    std::string info() const;
private:

};

std::ostream& operator<<(std::ostream& out, const Warrior& value);






class Healer: public Unit
{
public:
    Healer(int HP, int AP, int initiative, int row, int col);

    ~Healer();

private:

};

std::ostream& operator<<(std::ostream& out, const Healer& value);



#endif // UNIT_H
