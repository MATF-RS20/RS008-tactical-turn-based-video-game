#ifndef UNITQUEUE_H
#define UNITQUEUE_H


#include "Model/Units/unit.h"
#include <vector>


class UnitQueue
{
public:
    UnitQueue();

    ~UnitQueue();

    UnitQueue(const UnitQueue& other) = delete;
    const UnitQueue& operator= (const UnitQueue& other) = delete;

    void push_back(Unit* u);

    void pop_at(unsigned i);

    std::vector<Unit*>::iterator find_Unit(Unit* u);

    bool pop_Unit(Unit* u);

    Unit* current();

    Unit* next();

    void sortByInitiative();

    std::pair<bool, Player*> onePlayerLeft() const;

private:
    std::vector<Unit*> m_vector;
    unsigned m_index;
};

#endif // UNITQUEUE_H
