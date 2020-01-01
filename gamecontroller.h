#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Units/unit.h"

#include <vector>
#include <optional>

class UnitQueue;

class GameController
{
public:
    GameController();
    //TODO: singleton maybe?

    ~GameController();
private:
    UnitQueue* m_queue;
};





class UnitQueue
{
public:
    UnitQueue(){}

    void push_back(Unit u)
    {
        m_vector.push_back(u); //TODO: see emplace?
    }

    void pop_at(int i)
    {
        if (m_vector.size() > i) {
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
    std::optional<Unit> current()
    {
        if (m_vector.empty())
        {
            return {};
        }
        return {m_vector[m_index]};
    }
    //TODO
    Unit next();

private:
    //TODO: different implementation maybe?
    std::vector<Unit> m_vector;
    int m_index;
};


#endif // GAMECONTROLLER_H
