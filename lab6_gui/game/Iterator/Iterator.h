#ifndef GAME_ITERATOR_H
#define GAME_ITERATOR_H

#include "../Field/Field.h"

class IteratorOfField{
public:
    explicit IteratorOfField(Field& iter);
    void First();
    void Next();
    IteratorOfField& operator ++();
    IteratorOfField operator ++(int);
    bool IsDone();
    Cell* Current();
    Cell* operator *();
    bool IsBoard();
    bool IsAbleSt();
    bool IsAbleFn();
    bool IsEven();
    int ret_y();
    int ret_x();
private:
    int ind1, ind2;
    Field& iter_field;
    Cell* iter_cell;
};


#endif //GAME_ITERATOR_H
