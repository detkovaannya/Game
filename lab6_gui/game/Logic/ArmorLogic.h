#ifndef GAME_ARMORLOGIC_H
#define GAME_ARMORLOGIC_H

#include <random>
#include "../Field/Field.h"
#include "ObjectLogic.h"
#include "../Entities/Armor.h"

class ArmorLogic: public ObjectLogic{
public:
    ArmorLogic() = default;
    void put(Field& field) final;
    bool entity_exist() final;
    void createEntity() final;
    Object* getObject() final;
    void take(Field& field) final;
    bool is_put() final;
    std::string save() final;
    void load(int prop, int x, int y, bool taken, bool put) final;
    ~ArmorLogic();
private:
    void setEntityOnCell(Cell* cell) final;
    Armor* armor;
    bool isPut;
};


#endif //GAME_ARMORLOGIC_H
