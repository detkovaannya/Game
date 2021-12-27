#ifndef GAME_BUILDER_H
#define GAME_BUILDER_H

#include "../Iterator/Iterator.h"


class Builder{
public:
    virtual void Build_Floor(Field& f) = 0;
    virtual void Build_Block_Cells(Field& f) = 0;
    virtual void Build_Exit_Entire(Field& f) = 0;
};


#endif //GAME_BUILDER_H
