#ifndef GAME_BUILDER_H
#define GAME_BUILDER_H

#include "iterator.h"


class Builder{
public:
    //virtual ~Builder() = 0;
    virtual void Build_Base_Field(Field& f) = 0;
};


#endif //GAME_BUILDER_H
