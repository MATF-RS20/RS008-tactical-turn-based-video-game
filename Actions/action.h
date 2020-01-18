#ifndef ACTION_H
#define ACTION_H

#include <iostream>

class Action
{
public:
    virtual ~Action() = default;

    std::string description() const;
    std::string name();
    virtual bool use(); //TODO: make action do something.

protected:
    Action(int AP_cost);

    int m_AP_cost;
    std::string m_description;
    std::string m_name;
};

#endif // ACTION_H
