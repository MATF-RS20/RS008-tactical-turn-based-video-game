#include "action.h"

Action::Action(int AP_cost)
    : m_AP_cost(AP_cost)
{
    m_description = "No description.";
    m_name = "X";
}

bool Action::use()
{
    std::cerr << "Action use called on base action! (Testing)" << std::endl;
    return true;
}
