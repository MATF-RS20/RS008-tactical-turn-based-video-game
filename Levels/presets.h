#ifndef PRESETS_H
#define PRESETS_H

#include "Actions/action.h"

#include <map>

//TODO: add to gamecontroller and delete on level end
std::map<std::string, Action*>* createActionDict();



//TODO: replace this with actionDict:
// or delete them at a proper time to prevent memory leaks
#include <vector>
std::vector<Action*>* warriorActions = new std::vector<Action*>({new Action("Move", 2), new TestAction1("Attack", 5)});
std::vector<Action*>* healerActions = new std::vector<Action*>({new Action("Move", 1), new TestAction1("Heal", 1)});
//TODOEND

#endif // PRESETS_H
