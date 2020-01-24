#ifndef PRESETS_H
#define PRESETS_H

#include "Actions/action.h"

#include <map>

//TODO: add to gamecontroller and delete on level end
std::map<std::string, Action*>* createActionDict();

#endif // PRESETS_H
