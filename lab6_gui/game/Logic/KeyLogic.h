#ifndef GAME_KEYLOGIC_H
#define GAME_KEYLOGIC_H

#include <random>
#include "../Field/Field.h"
#include "../Entities/Key.h"
#include "ObjectLogic.h"

class KeyLogic: public ObjectLogic{
public:
    KeyLogic() = default;
    void put(Field& field) final;
    bool entity_exist() final;
    void createEntity() final;
    Object* getObject() final;
    void take(Field& field) final;
    bool is_put() final;
    std::string save() final;
    void load(int prop, int x, int y, bool taken, bool put) final;
    ~KeyLogic();
private:
    void setEntityOnCell(Cell* cell) final;
    Key* key;
    bool isPut;
};


#endif //GAME_KEYLOGIC_H
