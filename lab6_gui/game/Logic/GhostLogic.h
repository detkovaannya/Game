#ifndef GAME_GHOSTLOGIC_H
#define GAME_GHOSTLOGIC_H

#include "EntityLogic.h"
#include "../Entities/Ghost.h"
#include "../Iterator/Iterator.h"

class GhostLogic: public EntityLogic{
public:
    GhostLogic() = default;
    void act(Field& field, Player* player) final;
    bool entity_exist() final;
    void createEntity() final;
    Character * getEntity() final;
    void removeEntityFromCell(Field& field) final;
    bool alive() final;
    std::string save() final;
    void load(int xp, int att, int arm, int x, int y, bool en_al, bool on_f, int st_x,
              int direction_x, int st_y, int direction_y) final;
    ~GhostLogic();
private:
    void setEntityOnCell(Cell* cell) final;
    void dellEntityFromCell(Cell* cell) final;
    Ghost* ghost;
    std::pair<int, int> prev_position;
    int step;
    int down;
    bool en_alive_and_on_field;
};


#endif //GAME_GHOSTLOGIC_H
