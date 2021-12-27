#ifndef GAME_WEAPONLOGIC_H
#define GAME_WEAPONLOGIC_H

#include <random>
#include "../Field/Field.h"
#include "../Entities/Weapon.h"
#include "ObjectLogic.h"

class WeaponLogic: public ObjectLogic{
public:
    WeaponLogic() = default;
    void put(Field& field) final;
    bool entity_exist() final;
    void createEntity() final;
    Object* getObject() final;
    void take(Field& field) final;
    bool is_put() final;
    std::string save() final;
    void load(int prop, int x, int y, bool taken, bool put) final;
    ~WeaponLogic();
private:
    void setEntityOnCell(Cell* cell) final;
    Weapon* weapon;
    bool isPut;
};


#endif //GAME_WEAPONLOGIC_H
