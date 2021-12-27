#include <iostream>

#include "LoggerToConsole.h"
#include "../Entities/Player.h"
#include "../Entities/Ghost.h"
#include "../Entities/Enemy2.h"
#include "../Entities/Enemy3.h"


void LoggerToConsole::logging(Entity* obj, std::string str) {
    std::stringstream out;
    if (dynamic_cast<Player*>(obj))
        out << dynamic_cast<Player*>(obj);
    else if (dynamic_cast<Ghost*>(obj))
        out << dynamic_cast<Ghost*>(obj);
    else if (dynamic_cast<Enemy2*>(obj))
        out << dynamic_cast<Enemy2*>(obj);
    else if (dynamic_cast<Enemy3*>(obj))
        out << dynamic_cast<Enemy3*>(obj);
    std::cout << str << std::endl;
    std::cout << out.str();
}