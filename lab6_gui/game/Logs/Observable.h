#ifndef GAME_OBSERVABLE_H
#define GAME_OBSERVABLE_H

#include <string>
#include "SetLogger.h"

class Observable {
    SetLogger* obs;
public:
    void setObserver(SetLogger* ob);
    void notify(const std::string& str, Entity* obj);
};


#endif //GAME_OBSERVABLE_H
