#ifndef GAME_OBJECTLOGIC_H
#define GAME_OBJECTLOGIC_H

#include "../Field/Field.h"
#include "../Entities/Object.h"

class ObjectLogic {
public:
    ObjectLogic() = default;
    virtual void put(Field& field) = 0;
    virtual bool entity_exist() = 0;
    virtual void createEntity() = 0;
    virtual void setEntityOnCell(Cell* cell) = 0;
    virtual Object* getObject() = 0;
    virtual void take(Field& field) = 0;
    virtual bool is_put() = 0;
    virtual std::string save() = 0;
    virtual void load(int prop, int x, int y, bool taken, bool put) = 0;
    // virtual ~ObjectLogic() = 0;
};

#endif //GAME_OBJECTLOGIC_H
