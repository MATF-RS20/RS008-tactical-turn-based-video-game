#include "action.h"

Action::Action(std::string name, int AP_cost, gcAction type)
    : m_AP_cost(AP_cost)
    , m_gc_action(type)
    , m_name(name)
{
    m_description = "No description.";
    //m_name = "X";
}

bool Action::use()
{
    std::cerr << "Action use called on base action! (Testing)" << std::endl;
    return true;
}

std::string Action::name() const
{
    return m_name;
}


std::string Action::description() const
{
    return m_description;
}
