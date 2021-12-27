#include "LoggerToFile.h"

#include "../Entities/Character.h"
#include "../Entities/Player.h"
#include "../Entities/Ghost.h"
#include "../Entities/Enemy2.h"
#include "../Entities/Enemy3.h"


void LoggerToFile::logging(Entity* obj, std::string str){
    std::stringstream out;
    if (dynamic_cast<Player*>(obj))
        out << dynamic_cast<Player*>(obj);
    else if (dynamic_cast<Ghost*>(obj))
        out << dynamic_cast<Ghost*>(obj);
    else if (dynamic_cast<Enemy2*>(obj))
        out << dynamic_cast<Enemy2*>(obj);
    else if (dynamic_cast<Enemy3*>(obj))
        out << dynamic_cast<Enemy3*>(obj);
    logFile << str << std::endl;
    logFile << out.str();
}

LoggerToFile::LoggerToFile() {
    logFile.open("/home/anna/CLionProjects/game/Logs.txt", std::ios_base::out | std::ios_base::trunc);
}

LoggerToFile::~LoggerToFile() {
    logFile.close();
}
