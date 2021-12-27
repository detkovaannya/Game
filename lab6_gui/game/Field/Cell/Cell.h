#ifndef GAME_CELL_H
#define GAME_CELL_H

#include "../../Entities/Entity.h"

/*
 * IMP - 0 - impassable
 * EMP - 1 - empty
 * START - 2 - start
 * FIN - 3 - finish
 */

enum CELL_STATES {IMP = 0, EMP, START, FIN};

class Cell{
public:
    Cell(CELL_STATES st = IMP, Entity* ob = nullptr);
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    Cell(Cell&& other);
    Cell& operator=(Cell&& other);
    void SetState(CELL_STATES st);
    CELL_STATES GetState();
    bool IsEmpty() const;
    bool IsImpassable() const;
    void Set_Object(Entity* object);
    Entity* Get_Object();
    void Dell_Object();
private:
    Entity* obj;
    Entity* obj2;
    CELL_STATES state;
};


#endif //GAME_CELL_H
