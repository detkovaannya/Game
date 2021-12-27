#ifndef GAME_ENEMY2_H
#define GAME_ENEMY2_H

#include "Enemy.h"
#include "../Logs/Observable.h"
#include <sstream>


class Enemy2: public Enemy {  //public Observable{
public:
    Enemy2() = default;
    Enemy2(int x, int y, int heal = 200, int att = 30, int arm = 30);
    ENTITIES_STATES get_state() final;
    void fight(Player& player) final;
    bool is_exist() final;
    void set_health(int impact_force) final;
    void set_position(int x, int y) final;
    std::pair<int,int> get_position() final;
    friend std::stringstream & operator<<(std::stringstream & out, const Enemy2* obj);
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


#endif //GAME_ENEMY2_H
