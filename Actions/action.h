#ifndef ACTION_H
#define ACTION_H


#include "Controller/controller_actions.h"

#include <iostream>


class Action
{
public:
    Action(std::string name, int AP_cost);
    virtual ~Action() = default;

    std::string description() const;
    std::string name() const;
    virtual bool use(); //TODO: make action do something.

protected:

    int m_AP_cost;
    gcAction m_gc_action;
    std::string m_description;
    std::string m_name;
};


class TestAction1: public Action
{
public:
    TestAction1(std::string name, int AP_cost)
        :Action(name, AP_cost)
    {}

    bool use() override
    {
        std::cerr << "Test1 Action use() (Testing inheritance)." << std::endl;
        return true;
    }
};


#endif // ACTION_H
