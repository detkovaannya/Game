#ifndef GAME_ENEMY2LOGIC_H
#define GAME_ENEMY2LOGIC_H

#include "EntityLogic.h"
#include "../Entities/Enemy2.h"

class Enemy2Logic: public EntityLogic{
public:
    Enemy2Logic() = default;
    void act(Field& field, Player* player) final;
    bool entity_exist() final;
    void createEntity() final;
    Character * getEntity() final;
    void removeEntityFromCell(Field& field) final;
    bool alive() final;
    std::string save() final;
    void load(int xp, int att, int arm, int x, int y, bool en_al, bool on_f, int st_x,
              int direction_x, int st_y, int direction_y) final;
    ~Enemy2Logic();
private:
    void setEntityOnCell(Cell* cell) final;
    void dellEntityFromCell(Cell* cell) final;
    Enemy2* enemy2;
    std::pair<int, int> prev_position;
    int step;
    int left;
    bool en_alive_and_on_field;
};


#endif //GAME_ENEMY2LOGIC_H
