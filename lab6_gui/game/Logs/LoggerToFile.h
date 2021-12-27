#ifndef GAME_LOGGERTOFILE_H
#define GAME_LOGGERTOFILE_H

#include <string>
#include <fstream>
#include "Logger.h"

class LoggerToFile: public Logger{
public:
    LoggerToFile();
    void logging(Entity* obj, std::string str) final;
    ~LoggerToFile();
private:
    std::ofstream logFile;
};


#endif //GAME_LOGGERTOFILE_H
