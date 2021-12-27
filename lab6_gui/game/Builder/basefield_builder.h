#ifndef GAME_BASEFIELD_BUILDER_H
#define GAME_BASEFIELD_BUILDER_H

#include "builder.h"
#include <iostream>
#include <random>

class BaseFieldBuilder: public Builder{
public:
    void Build_Floor(Field& f) final;
    void Build_Block_Cells(Field& f) final;
    void Build_Exit_Entire(Field& f) final;
};


#endif //GAME_BASEFIELD_BUILDER_H
