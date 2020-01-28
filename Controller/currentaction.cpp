#include "currentaction.h"

CurrentAction::CurrentAction(gcAction type, position_t position, AP_cost_t cost)
{
    if (type == gcAction::move) {
        m_fields_to_add = 1;
        //TODO: add valid fields to map...
    }
}
