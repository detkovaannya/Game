#include <iostream>
#include "Cell.h"

Cell::Cell(CELL_STATES st, Entity* ob): state(st), obj(ob){}
Cell::Cell(const Cell& other){
    state = other.state;
    obj = nullptr;
    obj2 = nullptr;
}
Cell& Cell::operator=(const Cell& other){
    if(this != &other){
        state = other.state;
        obj = nullptr;
        obj2 = nullptr;
    }
    return *this;
}
Cell::Cell(Cell&& other){
    std::swap(state, other.state);
    std::swap(obj, other.obj);
    std::swap(obj2, other.obj2);
}
Cell& Cell::operator=(Cell&& other){
    if(this != &other){
        std::swap(state, other.state);
        std::swap(obj, other.obj);
        std::swap(obj2, other.obj2);
    }
    return *this;
}
void Cell::SetState(CELL_STATES st) {
    state = st;
}
CELL_STATES Cell::GetState() {
    return state;
}
bool Cell::IsEmpty() const{
    return (state == 1);
}
bool Cell::IsImpassable() const{
    return (state == 0);
}
void Cell::Set_Object(Entity* object) {
    if (!object){
        obj = nullptr;
        obj2 = nullptr;
        return;
    }
    if (!obj)
        obj = object;
    else if (obj != object){
        obj2 = obj;
        obj = object;
    }
}
Entity *Cell::Get_Object() {
    return obj;
}
void Cell::Dell_Object() {
    if (!obj2)
        obj = nullptr;
    else{
        obj = obj2;
        obj2 = nullptr;
    }
}

