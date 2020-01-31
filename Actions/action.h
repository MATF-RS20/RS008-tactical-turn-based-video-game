#ifndef ACTION_H
#define ACTION_H


#include "Model/type_definitions.h"

#include <iostream>


class Action
{
public:
    Action(std::string name, unsigned AP_cost, ActionType type = ActionType::move);
    virtual ~Action() = default;

    ActionType type() const;
    std::string name() const;
    std::string description() const;
    unsigned cost() const;

protected:

    unsigned m_AP_cost;
    ActionType m_type;
    std::string m_description;
    std::string m_name;
};


#endif // ACTION_H
