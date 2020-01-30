#include "action.h"

Action::Action(std::string name, unsigned AP_cost, ActionType type)
    : m_AP_cost(AP_cost)
    , m_type(type)
    , m_name(name)
{
    m_description = "No description.";
}

std::string Action::name() const
{
    return m_name;
}


std::string Action::description() const
{
    return m_description;
}


ActionType Action::type() const
{
    return m_type;
}


unsigned Action::cost() const
{
    return m_AP_cost;
}
