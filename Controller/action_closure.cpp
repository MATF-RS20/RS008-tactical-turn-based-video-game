#include "action_closure.h"

ActionClosure::ActionClosure(ActionType type, Grid* grid, Unit* unit, AP_cost_t cost)
    : m_type(type)
    , m_cost(cost)
    , m_unit(unit)
    , m_grid(grid)
{
    //std::cerr << "New closure: position = " << m_unit->position() << ", cost = " << std::to_string(cost) << std::endl;
    m_valid_fields = {};

    if (type == ActionType::move) {
        m_fields_to_add = 1;
        setValidFields();
    }
    if (type == ActionType::damage) {
        m_fields_to_add = 1;
        setValidFields();
    }
}

ActionClosure::~ActionClosure()
{
    //std::cerr << "Closure destroyed" << std::endl;
}


unsigned ActionClosure::fieldsToAdd() const
{
    return m_fields_to_add;
}

void ActionClosure::addField(Field *field)
{
    //check if field is valid...
    //TODO: add to map on closure creation
    //std::cerr << "ACTION CLOSURE: addField called!" << std::endl;
    //std::cerr << (bool)field << std::endl;
    if (m_fields_to_add < 1) {
        return;
    }
    if (!field || m_valid_fields.count(field->position()) == 0)
    {
        //std::cerr << "ACTION CLOSURE: Field not added!" << std::endl;
        return;
    }
    m_added_fields.push_back(field->position());

    if (m_fields_to_add > 0) {
        m_fields_to_add--;
    }
}


void ActionClosure::setValidFields()
{
    //TODO setValidFields(action_type, range...)
    if (!m_grid) {
        return;
    }
    unsigned row = m_unit->position().first,
             col = m_unit->position().second,
             rows = m_grid->size().first,
             cols = m_grid-> size().second;

    //TODO: based on action type
    // add only (or don't add) fields with units.
    // move -> no unit, damage -> unit!

    //TODO make position_t a class?
    unsigned left_bound = col > 0 ? col-1 : 0,
             right_bound = col < cols ? col+1 : cols,
             top_bound = row > 0 ? row-1 : 0,
            bottom_bound = row < rows ? row+1 : rows;

    for (unsigned row = top_bound; row <= bottom_bound; row++)
    {
        for (unsigned col = left_bound; col <= right_bound; col++)
        {
            m_valid_fields.insert({{row,col}, m_cost});
        }
    }
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

        m_unit->updateAP(m_cost);
        return;
    }
    else {
        return;
    }
}

void ActionClosure::doAction()
{
    if (m_type == ActionType::move) {
        //std::cerr << "ActionType::move!" << std::endl;
        if (m_added_fields.size() > 0) {
            move(m_unit, m_added_fields[0]);
        }
    }
}
