#ifndef ACTION_CLOSURE_H
#define ACTION_CLOSURE_H

#include "type_definitions.h"
#include "View/field.h"
#include "View/grid.h"

#include <map>


class ActionClosure
{
public:
    //TODO: pass an action object or some kind of struct?
    ActionClosure(ActionType type, Grid* grid, position_t position, AP_cost_t cost);
    ~ActionClosure();

    void setValidFields();
    void addField(Field* field);
    unsigned fieldsToAdd() const;

    void doAction();
    //Actions
    void move(Unit* unit, position_t position);
    void damage(Unit* unit);
    void heal(Unit* unit);


private:
    bool validField();
    void addFieldtoMap();

private:
    ActionType m_type;
    unsigned m_cost;
    position_t m_position; //active unit position
    Grid* m_grid;
    std::map<position_t, AP_cost_t> m_valid_fields; //position/AP_cost
    unsigned m_fields_to_add;
    std::vector<position_t> m_added_fields;
    //unsigned m_range;
};

#endif // ACTION_CLOSURE_H
