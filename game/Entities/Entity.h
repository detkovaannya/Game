#ifndef GAME_ICELL_H
#define GAME_ICELL_H

#include <utility>
#include <string>

enum ENTITIES_STATES {GHOST = 4, ENEMY2, ENEMY3, PLAYER, KEY, HEAL, WEAPON, ARMOR};
class Entity {
public:
    Entity() = default;
    virtual ENTITIES_STATES get_state() = 0;
    virtual bool is_exist() = 0;
    virtual void set_position(int x, int y) = 0;
    virtual std::pair<int,int> get_position() = 0;
    virtual std::string save() = 0;
};


#endif //GAME_ICELL_H

