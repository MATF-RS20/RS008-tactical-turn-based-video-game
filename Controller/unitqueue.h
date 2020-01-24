#ifndef UNITQUEUE_H
#define UNITQUEUE_H


#include "Units/unit.h"
#include <vector>


class UnitQueue
{
public:
    UnitQueue()
    {
        m_index = 0;
    }

    ~UnitQueue()
    {
        //TODO: smart pointers?
        for (Unit* u : m_vector) {
            delete u;
        }
        m_vector.clear();
    }

    void push_back(Unit* u)
    {
        m_vector.push_back(u); //TODO: see emplace?
    }

    void pop_at(unsigned i)
    {
        if (m_vector.size() > i) {
            std::cerr << "UnitQueue pop_at() bad index" << std::endl;
            return;
        }

        m_vector.erase(std::begin(m_vector) + i);

        if (m_index >= i) {
            m_index--;
        }
    }

    //TODO pop_Unit, get_Unit
    /*void pop_Unit(Unit* u)
    {
        auto it = std::find(std::begin(m_vector), std::end(m_vector), u);
        //TODO: Redefine Unit == operator?
        // Use unit id?!
        //TODO: add m_id to Units for comparison?
    }*/

    Unit* current()
    {
        if (m_vector.empty())
        {
            return nullptr;
        }
        return m_vector[m_index];
    }


    Unit* next()
    {
        if (m_vector.empty())
        {
            return nullptr;
        }
        if (m_index >= m_vector.size()-1)
        {
            m_index = 0;
        }
        else {
            m_index++;
        }
        return m_vector[m_index];
    }

private:
    std::vector<Unit*> m_vector;
    unsigned m_index;
};

#endif // UNITQUEUE_H
