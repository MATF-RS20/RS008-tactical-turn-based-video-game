#include "action_closure.h"

ActionClosure::ActionClosure(ActionType type, Grid* grid, Unit* unit, AP_cost_t cost)
    : m_type(type)
    , m_cost(cost)
    , m_unit(unit)
    , m_grid(grid)
{
    //std::cerr << "New closure: position = " << m_unit->position() << ", cost = " << std::to_string(cost) << std::endl;
    m_valid_fields = {};
    setNumberOfFieldsToAdd(type);
    setValidFields(type);
}

ActionClosure::~ActionClosure()
{
    colorValidFields(DEFAULT_FIELD_COLOR);
    //std::cerr << "Closure destroyed" << std::endl;
}


unsigned ActionClosure::fieldsToAdd() const
{
    return m_fields_to_add;
}

void ActionClosure::addField(Field *field)
{
    if (m_fields_to_add < 1) {
        return;
    }
    if (!field || m_valid_fields.count(field->position()) == 0)
    {
        //std::cerr << "ACTION CLOSURE: Field not added!" << std::endl;
        return;
    }
    m_added_fields.push_back(field->position()); //TODO: cost from map.

    if (m_fields_to_add > 0) {
        m_fields_to_add--;
    }
}


void ActionClosure::setValidFields(ActionType type)
{
    //TODO setValidFields(action_type, range...)
    if (!m_grid) {
        return;
    }
    unsigned row = m_unit->position().first,
             col = m_unit->position().second,
             rows = m_grid->size().first - 1, //subtract 1 in grid definition?
             cols = m_grid-> size().second - 1;

    //TODO make position_t a class?
    unsigned left_bound = col > 0 ? col-1 : 0,
             right_bound = col < cols ? col+1 : cols,
             top_bound = row > 0 ? row-1 : 0,
            bottom_bound = row < rows ? row+1 : rows;


    //TODO: clean up this code. Filter maybe?
    for (unsigned row = top_bound; row <= bottom_bound; row++)
    {
        for (unsigned col = left_bound; col <= right_bound; col++)
        {
            if (validField({row,col}, type)) {
                m_valid_fields.insert({{row,col}, m_cost});
            }
        }
    }
    colorValidFields(DEFAULT_HIGHLIGHT_FIELD_COLOR);
}


void ActionClosure::colorValidFields(QColor color)
{
    for (auto it = m_valid_fields.begin(); it != m_valid_fields.end(); it++)
    {
        m_grid->at(it->first)->setColor(color);
    }
}


bool ActionClosure::validField(position_t position, ActionType type)
{
    if (!m_grid) {
        return false;
    }
    Field* field = m_grid->at(position);
    return validField(field, type);
}


bool ActionClosure::validField(Field* field, ActionType type)
{
    if (!field) {
        return false;
    }

    if (type == ActionType::move)
    {
        if (field->unit()) {
            return false;
        }
        return true;
    }

    if (type == ActionType::damage)
    {
        Unit* target = field->unit();
        if (!target || target == m_unit) {
            return false;
        }
        if (target->player() != m_unit->player()) {
            return true;
        }
        return false;
    }

    if (type == ActionType::heal)
    {
        Unit* target = field->unit();
        if (!target) {
            return false;
        }
        if (samePlayer(m_unit, target)) {
            return true;
        }
        return false;
    }

    return false;
}


bool samePlayer(Unit* unit1, Unit* unit2) {
    return *(unit1->player()) == *(unit2->player());
}


void ActionClosure::move(Unit* unit, position_t position)
{
    if (!m_grid) {
        //TODO: this shouldn't happen, throw some error?
        return;
    }

    auto old_position = unit->position();
    if (old_position == position)
    {
        // no moving so no action point reduction.
        // also this shouldn't happen.
        return;
    }

    if (m_grid->placeUnit(position, unit))
    {
        m_grid->removeUnit(old_position);
        return;
    }
    else {
        return;
    }
}

void ActionClosure::doAction()
{
    if (m_type == ActionType::move) {
        //TODO: check vector size in a generic way
        // to work for move, damage, heal ...
        // based on setNumberOfFieldsToAdd logic
        if (m_added_fields.size() > 0) {
            move(m_unit, m_added_fields[0]);
        }
    }
    m_unit->updateAP(m_cost);
}


void ActionClosure::setNumberOfFieldsToAdd(ActionType type)
{
    switch (type) {

    case ActionType::move :
        m_fields_to_add = 1;
        break;

    case ActionType::damage :
        m_fields_to_add = 1;
        break;

    case ActionType::heal :
        m_fields_to_add = 1;
        break;
    }
}
