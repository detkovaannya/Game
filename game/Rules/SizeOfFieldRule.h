#ifndef GAME_SIZEOFFIELDRULE_H
#define GAME_SIZEOFFIELDRULE_H

#include "../Field/Field.h"
#include "../Builder/basefield_builder.h"
#include "../Builder/Director.h"

template<int size>
class SizeOfFieldRule {
public:
    Field* GenerateFieldWithRuledSize(){
        Field* f; // объект поля
        f = new Field(size, size);
        BaseFieldBuilder builder; // объект строителя
        Director dir; // директор - генерирует поле
        dir.CreateField(builder, *f);
        return f;
    }
    int GetSizeOfWindow(){
        return size;
    }
};


#endif //GAME_SIZEOFFIELDRULE_H
