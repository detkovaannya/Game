#ifndef GAME_HEALLOGIC_H
#define GAME_HEALLOGIC_H

#include <random>
#include "../Field/Field.h"
#include "../Entities/Heal.h"
#include "ObjectLogic.h"

class HealLogic: public ObjectLogic{
public:
    HealLogic() = default;
    void put(Field& field) final;
    bool entity_exist() final;
    void createEntity() final;
    Object* getObject() final;
    void take(Field& field) final;
    bool is_put() final;
    std::string save() final;
    void load(int prop, int x, int y, bool taken, bool put) final;
    ~HealLogic();
private:
    void setEntityOnCell(Cell* cell) final;
    Heal* heal;
    bool isPut;
};


#endif //GAME_HEALLOGIC_H
