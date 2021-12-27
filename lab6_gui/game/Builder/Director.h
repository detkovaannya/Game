#ifndef GAME_DIRECTOR_H
#define GAME_DIRECTOR_H

#include "builder.h"
#include "basefield_builder.h"

class Director {
public:
    void CreateField(Builder& bildr, Field &f);
};


#endif //GAME_DIRECTOR_H
