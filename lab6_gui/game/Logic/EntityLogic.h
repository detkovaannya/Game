#ifndef GAME_ENTITYLOGIC_H
#define GAME_ENTITYLOGIC_H

#include "../Field/Field.h"
#include "../Entities/Player.h"

class EntityLogic {
public:
    EntityLogic() = default;
    virtual void act(Field& field, Player* player) = 0;
    virtual bool entity_exist() = 0;
    virtual void createEntity() = 0;
    virtual void setEntityOnCell(Cell* cell) = 0;
    virtual void dellEntityFromCell(Cell* cell) = 0;
    virtual Character * getEntity() = 0;
    virtual void removeEntityFromCell(Field& field) = 0;
    virtual bool alive() = 0;
    virtual std::string save() = 0;
    virtual void load(int xp, int att, int arm, int x, int y, bool en_al, bool on_f, int st_x,
                      int direction_x, int st_y, int direction_y) = 0;
//    virtual ~EntityLogic() = 0;
};



#endif //GAME_ENTITYLOGIC_H
