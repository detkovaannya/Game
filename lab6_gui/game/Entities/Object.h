#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Entity.h"

class Object: public Entity{
public:
    Object() = default;
    virtual int take() = 0;
    virtual void load(int prop, int x, int y, bool taken) = 0;
};

#endif //GAME_OBJECT_H
