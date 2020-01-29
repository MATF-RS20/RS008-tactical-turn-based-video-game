#ifndef TYPE_DEFINITIONS_H
#define TYPE_DEFINITIONS_H

#include <iostream>

enum ControllerState {init, action_waiting_input, action_ready};
enum class ActionType { move };

using position_t = std::pair<unsigned, unsigned>;

using AP_cost_t = unsigned;

using paintSize_t = unsigned;

#endif // TYPE_DEFINITIONS_H
