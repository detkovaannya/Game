#ifndef GAME_SETLOGGER_H
#define GAME_SETLOGGER_H

#include "LoggerToConsole.h"
#include "LoggerToFile.h"

class SetLogger {
private:
    LoggerToConsole* loggerToConsole;
    LoggerToFile* loggerToFile;
    void ChooseLoggingMethod();

public:
    SetLogger();
    void update(const std::string& str, Entity* obj);
    ~SetLogger();
};


#endif //GAME_SETLOGGER_H
