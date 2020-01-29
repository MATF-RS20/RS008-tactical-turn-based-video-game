#include "action_closure.h"

ActionClosure::ActionClosure(ActionType type, position_t position, AP_cost_t cost)
{
    std::cerr << "New closure: position = " << position << ", cost = " << std::to_string(cost) << std::endl;
    if (type == ActionType::move) {
        m_fields_to_add = 1;
        //TODO: add valid fields to map...
    }
}

ActionClosure::~ActionClosure()
{
    std::cerr << "Closure destroyed" << std::endl;
}
