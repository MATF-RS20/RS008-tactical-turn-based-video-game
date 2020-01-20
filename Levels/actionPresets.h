#ifndef ACTIONPRESETS_H
#define ACTIONPRESETS_H

#include "Actions/action.h"

#include <vector>


//Put this in a cpp file?

//TODO: delete vectors on level(gameController) end?
std::vector<Action*>* warriorActions = new std::vector<Action*>({new Action("Move", 2), new TestAction1("Attack", 5)});
std::vector<Action*>* healerActions = new std::vector<Action*>({new Action("Move", 1), new TestAction1("Heal", 1)});


#endif // ACTIONPRESETS_H
