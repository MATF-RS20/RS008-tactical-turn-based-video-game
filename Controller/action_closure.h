#ifndef ACTION_CLOSURE_H
#define ACTION_CLOSURE_H

#include "type_definitions.h"

#include <map>


class ActionClosure
{
public:
    //TODO: pass an action object or some kind of struct?
    ActionClosure(ActionType type, position_t position, AP_cost_t cost);
    ~ActionClosure();
    void addFieldtoMap();

private:
    //position/AP_cost
    std::map<position_t, AP_cost_t> valid_fields;
    AP_cost_t m_fields_to_add;
};

#endif // ACTION_CLOSURE_H
