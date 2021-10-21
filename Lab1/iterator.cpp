#include "iterator.h"

// |+| перегрузить *, ++

IteratorOfField::IteratorOfField(Field& iter): iter_field(iter), ind1(0), ind2(0) {
    iter_cell = iter_field.get_cell(ind2,ind1);
}
void IteratorOfField::First() {
    iter_cell = iter_field.get_cell(0,0);
}
void IteratorOfField::Next() {
    if (ind1 < iter_field.get_height() && ind2 < iter_field.get_width() - 1)
        ind2++;
    else if (ind1 < iter_field.get_height() && ind2 == iter_field.get_width() - 1) {
        ind2 = 0;
        ind1++;
    }
    if (ind1 == iter_field.get_height())
        iter_cell = nullptr;
    else
        iter_cell = iter_field.get_cell(ind2, ind1);
}
IteratorOfField& IteratorOfField::operator ++(){
    Next();
    return *this;
}
IteratorOfField IteratorOfField::operator ++(int){
    IteratorOfField tmp(iter_field);
    Next();
    return tmp;
}
bool IteratorOfField::IsDone() {
    return (iter_cell == nullptr);
}
Cell* IteratorOfField::Current() {
    return iter_cell;
}
Cell* IteratorOfField::operator *(){
    return iter_cell;
}
bool IteratorOfField::IsBoard() {
    return (ind1 == 0 || ind1 == iter_field.get_height() - 1 || ind2 == 0
    || ind2 == iter_field.get_width() - 1);
}
bool IteratorOfField::IsAbleSt() {
    return (ind2 == 1);
}
bool IteratorOfField::IsAbleFn() {
    return (ind2 == iter_field.get_width() - 2);
}
bool IteratorOfField::IsEven() {
    return (((ind2 % 3 == 1 || ind2 % 3 == 0) && ind1 % 2 == 1) && iter_cell->IsEmpty());
}
int IteratorOfField::ret_x() {
    return ind2;
}
int IteratorOfField::ret_y() {
    return ind1;
}



