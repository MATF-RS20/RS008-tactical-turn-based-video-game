#include "Controller/unitqueue.h"

UnitQueue::UnitQueue()
{
    m_index = 0;
}


UnitQueue::~UnitQueue()
{
    for (Unit* u : m_vector) {
        delete u;
    }
    m_vector.clear();
}


void UnitQueue::push_back(Unit* u)
{
    m_vector.push_back(u); //TODO: see emplace?
}


void UnitQueue::pop_at(unsigned i)
{
    if (m_vector.size() >= i) {
        std::cerr << "UnitQueue pop_at() bad index" << std::endl;
        return;
    }

    m_vector.erase(std::begin(m_vector) + i);

    if (m_index >= i) {
        m_index--;
    }
}


std::vector<Unit*>::iterator UnitQueue::find_Unit(Unit* u)
{
    for (auto it = m_vector.begin(); it < m_vector.end(); it++)
    {
        if (*(*it) == *u) {
            return it;
        }
    }
    return m_vector.end();
}


bool UnitQueue::pop_Unit(Unit* u)
{
    auto it = find_Unit(u);
    if (it == m_vector.end()) {
        return false;
    }

    if (it == (m_vector.begin() + m_index))
    {
        //TODO: game controller
        // shouldn't delete m_active_unit?
        return false;
    }

    if (it < (m_vector.begin() + m_index)) {
        m_index--;
    }

    delete *it;
    m_vector.erase(it);
    return true;
}


Unit* UnitQueue::current()
{
    if (m_vector.empty())
    {
        return nullptr;
    }
    return m_vector[m_index];
}


Unit* UnitQueue::next()
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


void UnitQueue::sortByInitiative()
{
    std::sort(m_vector.begin(), m_vector.end(), [](Unit* a, Unit* b){
        return *b < *a;
    });
}


std::pair<bool, Player*> UnitQueue::onePlayerLeft() const
{
    if (m_vector.empty())
    {
        //raise noUnit error?
        return {false, nullptr};
    }

    auto firstUnit = m_vector[0];
    if (!firstUnit)
    {
        return {false, nullptr};
    }
    auto firstPlayer = firstUnit->player();
    if (!firstPlayer)
    {
        //error - player not set.
        return {false, nullptr};
    }

    for (auto unit: m_vector)
    {
        Player player = *(unit->player());
        if (player != *firstPlayer) {
            return {false, firstPlayer}; //nullptr as second argument indicates error
        }
    }
    return {true, firstPlayer};
}
