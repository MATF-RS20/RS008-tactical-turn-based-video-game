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


unsigned ActionClosure::fieldsToAdd() const
{
    return m_fields_to_add;
}

void ActionClosure::addField(Field *field)
{
    //check if field is valid...
    //TODO: add to map on closure creation
    std::cerr << "Adding field... TODO: add the field!" << std::endl;

    //TODO: add the field before this!
    if (m_fields_to_add > 0) {
        m_fields_to_add--;
    }
}
