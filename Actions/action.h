#ifndef ACTION_H
#define ACTION_H


#include "type_definitions.h"

#include <iostream>


class Action
{
public:
    Action(std::string name, int AP_cost, ActionType type = ActionType::move);
    virtual ~Action() = default;

    std::string description() const;
    std::string name() const;
    ActionType type() const;
    unsigned cost() const;
    virtual bool use(); //TODO: make action do something.

protected:

    unsigned m_AP_cost; //TODO: alias type with using
    ActionType m_gc_action;
    std::string m_description;
    std::string m_name;
};


class TestAction1: public Action
{
public:
    TestAction1(std::string name, int AP_cost)
        :Action(name, AP_cost, ActionType::move)
    {}

    bool use() override
    {
        std::cerr << "Test1 Action use() (Testing inheritance)." << std::endl;
        return true;
    }
};


#endif // ACTION_H
