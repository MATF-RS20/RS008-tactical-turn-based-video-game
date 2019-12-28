#ifndef UNIT_H
#define UNIT_H

#include <iostream>

class Unit
{
public:
    virtual ~Unit() = default;

    //virtual Unit * Copy() const = 0;

    //getters
    /*
    int HP() const;
    int AP() const;
    int initiative() const;
    int row() const;
    int col() const;
    */

protected:
    Unit(int HP, int AP, int initiative, int row, int col);

    //HealthPoints, ActionPoints
    int _HP,
        _AP,
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
