#ifndef CURRENTACTION_H
#define CURRENTACTION_H

#include "type_definitions.h"

#include <map>


class CurrentAction
{
public:
    //TODO: pass an action object or some kind of struct?
    CurrentAction(ActionType type, position_t position, AP_cost_t cost);
    void addFieldtoMap();

private:
    //position/AP_cost
    std::map<position_t, AP_cost_t> valid_fields;
    unsigned m_fields_to_add;
};

#endif // CURRENTACTION_H
