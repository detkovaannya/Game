#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <string>
#include "Entity.h"
#include "../Logs/Observable.h"

class Character: public Entity, public Observable{
public:
    Character() = default;
    virtual void set_health(int impact_force) = 0;
};


#endif //GAME_CHARACTER_H
