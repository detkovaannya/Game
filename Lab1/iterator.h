#ifndef GAME_ITERATOR_H
#define GAME_ITERATOR_H

#include "field.h"

class IteratorOfField{
public:
    explicit IteratorOfField(Field* iter);
    void First();
    void Next();
    bool IsDone();
    Cell* Current();
    bool Is_Board();
    bool Is_St();
    bool Is_Fn();
    bool Is_Even();
    int ret_y();
    int ret_x();
private:
    int ind1, ind2;
    Field* iter_field;
    Cell* iter_cell;
};


#endif //GAME_ITERATOR_H
