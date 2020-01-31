#ifndef ACTION_CLOSURE_H
#define ACTION_CLOSURE_H

#include "Model/type_definitions.h"
#include "View/field.h"
#include "View/grid.h"

#include <map>

#define DEFAULT_HIGHLIGHT_FIELD_COLOR Qt::gray


class ActionClosure
{
public:
    //TODO: pass an action object or some kind of struct?
    ActionClosure(ActionType type, Grid* grid, Unit* unit, AP_cost_t cost);
    ~ActionClosure();

    void addField(Field* field);
    unsigned fieldsToAdd() const;


    void doAction();
    //Actions
    void move(Unit* unit, position_t position);
    void damage(Unit* unit);
    void heal(Unit* unit);


private:
    void setValidFields(ActionType type);
    bool validField(position_t position, ActionType type);
    bool validField(Field* field, ActionType type);
    void addFieldtoMap();
    void setNumberOfFieldsToAdd(ActionType type);
    void colorValidFields(QColor color);

private:
    ActionType m_type;
    unsigned m_cost;
    Unit* m_unit;
    Grid* m_grid;
    std::map<position_t, AP_cost_t> m_valid_fields; //position/AP_cost
    unsigned m_fields_to_add;
    std::vector<position_t> m_added_fields;
    //unsigned m_range;
};


bool samePlayer(Unit* unit1, Unit* unit2);

#endif // ACTION_CLOSURE_H
