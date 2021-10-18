#ifndef GAME_BASEFIELD_BUILDER_H
#define GAME_BASEFIELD_BUILDER_H

#include "builder.h"
#include <iostream>
#include <random>

class BaseFieldBuilder: public Builder{
public:
    void Build_Base_Field(Field& field) final;
};


#endif //GAME_BASEFIELD_BUILDER_H
