#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Units/unit.h"
#include "grid.h"

#include <vector>
#include <optional>

class UnitQueue;

class GameController
{
public:
    GameController();
    //TODO: singleton maybe?

    ~GameController();

    void setGrid(Grid* g);
    void addUnit(Unit* u);
    Unit* activeUnit();
    void startGame();
    void endTurn();
private:
    UnitQueue* m_queue;
    Unit* m_active_unit;
    Grid* m_grid;
};





class UnitQueue
{
public:
    UnitQueue()
    {
        m_index = 0;
    }

    void push_back(Unit* u)
    {
        m_vector.push_back(u); //TODO: see emplace?
    }

    void pop_at(int i)
    {
        if (m_vector.size() > i || i < 0) {
            std::cerr << "UnitQueue pop_at() bad index" << std::endl;
            return;
        }

        m_vector.erase(std::begin(m_vector) + i);

        if (m_index >= i) {
            m_index--;
        }
    }

    //TODO pop_Unit, get_Unit
    /*void pop_Unit(Unit u)
    {
        auto it = std::find(std::begin(m_vector), std::end(m_vector), u);
        //TODO: Redefine Unit == operator?
        //TODO: add m_id to Units for comparison?
    }*/

    //TODO: referance return?
    Unit* current()
    {
        if (m_vector.empty())
        {
            return nullptr;
        }
        return m_vector[m_index];
    }
    //TODO
    Unit* next()
    {
        if (m_vector.empty())
        {
            return nullptr;
        }
        if (m_index >= m_vector.size())
        {
            return m_vector[0];
        }
        else {
            m_index++;
            return m_vector[m_index];
        }
    }

private:
    //TODO: different implementation maybe?
    std::vector<Unit*> m_vector;
    int m_index;
};


#endif // GAMECONTROLLER_H
