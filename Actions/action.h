#ifndef ACTION_H
#define ACTION_H

#include <iostream>

class Action
{
public:
    virtual ~Action() = default;

protected:
    int m_AP_cost;
    std::string m_description;

protected:
    Action(int AP_cost);
};

#endif // ACTION_H
