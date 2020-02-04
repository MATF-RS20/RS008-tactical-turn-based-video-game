#ifndef ACTION_CLOSURE_H
#define ACTION_CLOSURE_H

#include "unitqueue.h"
#include "Model/type_definitions.h"
#include "View/field.h"
#include "View/grid.h"

#include <map>

#define DEFAULT_HIGHLIGHT_FIELD_COLOR Qt::gray


class ActionClosure
{
public:
    //TODO: pass an action object or some kind of struct?
    ActionClosure(Action action, Grid* grid, UnitQueue* uq);
    ~ActionClosure();

    void addField(Field* field);
    unsigned fieldsToAdd() const;
    std::string info() const;

    void doAction();


private:

    Field* fieldAt(position_t position) const;
    Unit* unitAt(position_t position) const;


    //Actions
    void move(position_t position);
    void damage(Unit* target);
    void damage(position_t position);
    void heal(Unit* target);
    void heal(position_t position);


    void setValidFields(ActionType type);
    bool validField(position_t position, ActionType type);
    bool validField(Field* field, ActionType type);
    void addFieldtoMap();
    void setNumberOfFieldsToAdd(ActionType type);
    unsigned NumberOfFieldsToAdd(ActionType type);
    void colorValidFields(QColor color);
    void kill(Unit* target);

private:
    ActionType m_type;
    unsigned m_intensity;
    unsigned m_cost;
    std::string m_name;

    UnitQueue* m_queue;
    Unit* m_unit;
    Grid* m_grid;
    std::map<position_t, AP_cost_t> m_valid_fields; //position/AP_cost
    unsigned m_fields_to_add;
    std::vector<position_t> m_added_fields;
    //unsigned m_range;
};


bool samePlayer(Unit* unit1, Unit* unit2);

#endif // ACTION_CLOSURE_H
