#ifndef GAME_LOGGER_H
#define GAME_LOGGER_H

#include <vector>
#include <string>
#include "../Entities/Entity.h"


class Logger { // observer
public:
    virtual void logging(Entity* obj, std::string str) = 0;
};


#endif //GAME_LOGGER_H
