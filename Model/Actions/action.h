#ifndef ACTION_H
#define ACTION_H


#include "Model/type_definitions.h"

#include <iostream>


class Action
{
public:
    Action(std::string name, ActionType type, unsigned intensity, unsigned AP_cost);
    virtual ~Action() = default;

    ActionType type() const;
    std::string name() const;
    std::string description() const;
    unsigned intensity() const;
    unsigned cost() const;

protected:

    const ActionType m_type;
    const unsigned m_intensity;
    const unsigned m_AP_cost;
    const std::string m_name;
    const std::string m_description;
};


#endif // ACTION_H
