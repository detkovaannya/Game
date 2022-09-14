#ifndef GAME_LOGGERTOCONSOLE_H
#define GAME_LOGGERTOCONSOLE_H

#include "Logger.h"

class LoggerToConsole: public Logger{
public:
    void logging(Entity* obj, std::string str) final;
};


#endif //GAME_LOGGERTOCONSOLE_H
