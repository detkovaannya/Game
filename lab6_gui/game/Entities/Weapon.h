#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include "Object.h"

class Weapon: public Object{
public:
    Weapon() = default;
    Weapon(int x, int y, int prop = 20);
    ENTITIES_STATES get_state() final;
    bool is_exist() final;
    int take() final;
    void set_position(int x, int y) final;
    std::pair<int,int> get_position() final;
    std::string save() final;
    void load(int prop, int x, int y, bool taken) final;
private:
    int property;
    std::pair<int, int> cur_position; // позиция на поле: x и y
    ENTITIES_STATES state; // тип, нужен для отрисовки и узнавания
    bool exist;
};


#endif //GAME_WEAPON_H
