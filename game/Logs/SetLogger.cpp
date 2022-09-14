#include <iostream>
#include "SetLogger.h"


SetLogger::SetLogger(): loggerToConsole(nullptr), loggerToFile(nullptr) {
    this->ChooseLoggingMethod();
}

void SetLogger::ChooseLoggingMethod() {
    int command;
    std::cout << "If you want logging to console, press 0, to file - 1, to file and console - press 2. "
                 "After press ENTER.\nIf you input different command, program will choose default logging to console.\n";
    std::cin >> command;
    switch (command) {
        case 0:
            loggerToConsole = new LoggerToConsole;
            break;
        case 1:
            loggerToFile = new LoggerToFile;
            break;
        case 2:
            loggerToConsole = new LoggerToConsole;
            loggerToFile = new LoggerToFile;
            break;
        default:
            loggerToConsole = new LoggerToConsole;
            break;
    }
}

void SetLogger::update(const std::string& str, Entity *obj) {
    if(loggerToFile)
        loggerToFile->logging(obj, str);
    if(loggerToConsole)
        loggerToConsole->logging(obj, str);
}

SetLogger::~SetLogger() {
    delete loggerToConsole;
    delete loggerToFile;
}
