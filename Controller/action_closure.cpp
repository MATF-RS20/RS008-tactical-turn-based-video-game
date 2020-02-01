#include "action_closure.h"

ActionClosure::ActionClosure(Action action, Grid* grid, UnitQueue* uq)
    : m_type(action.type())
    , m_intensity(action.intensity())
    , m_cost(action.cost())
    , m_queue(uq)
    , m_unit(uq->current())
    , m_grid(grid)
{
    //std::cerr << "New closure: position = " << m_unit->position() << ", cost = " << std::to_string(cost) << std::endl;
    m_valid_fields = {};
    m_fields_to_add = NumberOfFieldsToAdd(m_type);
    setValidFields(m_type);
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


unsigned ActionClosure::NumberOfFieldsToAdd(ActionType type)
{
    switch (type) {

    case ActionType::move :
        return 1;

    case ActionType::damage :
        return 1;

    case ActionType::heal :
        return 1;
    }
    // default
    return 1;
}


bool samePlayer(Unit* unit1, Unit* unit2) {
    return *(unit1->player()) == *(unit2->player());
}


Field* ActionClosure::fieldAt(position_t position) const
{
    if (!m_grid) {
        return nullptr;
    }
    return m_grid->at(position);
}


Unit* ActionClosure::unitAt(position_t position) const
{
    auto f = fieldAt(position);
    if (!f) {
        return nullptr;
    }
    auto u = f->unit();
    return u;
}


void ActionClosure::doAction()
{
    if (m_added_fields.size() < NumberOfFieldsToAdd(m_type)) {
        return;
    }
    else {
        if (m_type == ActionType::move) {
            move(m_added_fields[0]);
        }
        if (m_type == ActionType::heal) {
            heal(m_added_fields[0]);
        }
        if (m_type == ActionType::damage) {
            damage(m_added_fields[0]);
        }
        m_unit->updateAP(static_cast<int>(m_cost)); //TODO
        return;
    }
}


void ActionClosure::move(position_t position)
{
    if (!m_grid) {
        //TODO: this shouldn't happen, throw some error?
        return;
    }

    auto old_position = m_unit->position();
    if (old_position == position)
    {
        // no moving so no action point reduction.
        // also this shouldn't happen.
        return;
    }

    if (m_grid->placeUnit(position, m_unit))
    {
        m_grid->removeUnit(old_position);
        return;
    }
    else {
        return;
    }
}


void ActionClosure::heal(Unit* target)
{
    if (target) {
        target->updateHealth(m_intensity);
    }
}


void ActionClosure::heal(position_t position)
{
    heal(unitAt(position));
}


void ActionClosure::damage(Unit* target)
{
    if (target) {
        target->updateHealth(-m_intensity);
        if (target->HP_left() == 0) {
            kill(target);
        }
    }
}


void ActionClosure::kill(Unit* target)
{
    auto field = fieldAt(target->position());
    field->removeUnit();
    //TODO: do some checks?
    m_queue->pop_Unit(target);
    field->update();
}


void ActionClosure::damage(position_t position)
{
    damage(unitAt(position));
}

std::string ActionClosure::info() const
{
    //auto actionInfo =
    return "Closure active. TODO"; //TODO: nice output
}
