#include "action.h"

Action::Action(std::string name, ActionType type, unsigned intensity, unsigned AP_cost)
    : m_type(type)
    , m_intensity(intensity)
    , m_AP_cost(AP_cost)
    , m_name(name)
    , m_description("No description.")
{}

std::string Action::name() const
{
    return m_name;
}


ActionType Action::type() const
{
    return m_type;
}


unsigned Action::cost() const
{
    return m_AP_cost;
}


unsigned Action::intensity() const
{
    return m_intensity;
}


std::string Action::description() const
{
    return m_description;
}
