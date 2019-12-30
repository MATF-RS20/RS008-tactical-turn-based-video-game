#ifndef UNIT_H
#define UNIT_H

#include <iostream>

class Unit
{
public:
    virtual ~Unit() = default;

    //virtual Unit * Copy() const = 0;

    std::pair<int,int> position() const;
    std::pair<int, int> health() const;
    void updateHealth(int change);

protected:
    Unit(int HP, int AP, int initiative, int row, int col);

    //HealthPoints, ActionPoints
    int _max_HP,
        _remaining_HP,
        _max_AP,
        _remaining_AP,
        _initiative;
    //TODO action class
    //std::vector<> _actions;
    int _row,
        _col;
};

std::ostream& operator<<(std::ostream& out, const Unit& value);









class Warrior: public Unit
{
public:
    Warrior(int HP, int AP, int initiative, int row, int col);

    ~Warrior();

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
