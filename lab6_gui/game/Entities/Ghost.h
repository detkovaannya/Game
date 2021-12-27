#ifndef GAME_GHOST_H
#define GAME_GHOST_H

#include "Enemy.h"
#include "../Logs/Observable.h"
#include <sstream>

class Ghost: public Enemy{ // , public Observable{
public:
    Ghost() = default;
    Ghost(int x, int y, int heal = 100, int att = 10, int arm = 20);
    ENTITIES_STATES get_state() final;
    void fight(Player& player) final;
    bool is_exist() final;
    void set_health(int impact_force) final;
    void set_position(int x, int y) final;
    std::pair<int,int> get_position() final;
    friend std::stringstream &operator<<(std::stringstream &out, const Ghost *obj);
    std::string save() final;
    void load(int xp, int att, int arm, int x, int y, bool en_al);
private:
    int health; // здоровье врага
    int attack; // сила атаки
    int armor; // броня
    std::pair<int, int> cur_position; // позиция на поле: x и y
    ENTITIES_STATES state; // тип, нужен для отрисовки и узнавания
    bool alive;
};


#endif //GAME_GHOST_H
