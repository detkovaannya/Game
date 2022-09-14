#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <utility>
#include "Object.h"
#include "../Field/Cell/Cell.h"
#include "Character.h"
#include "../Logs/Observable.h"
#include <sstream>

class Player: public Character { //, public Observable{
private:
    int health; // здоровье игрока
    int attack; // сила атаки
    int armor; // броня
    int keys; // количество ключей во время игры, для победы нужно 3, выпадают с монстров
    int killed_enemies; // количество убитых врагов
    std::pair<int, int> cur_position; // позиция на поле: x и y
    ENTITIES_STATES state; // тип, нужен для отрисовки и узнавания
    bool alive;
public:
    Player() = default;
    Player(int x, int y, int heal = 500, int att = 50);
    void interact(Entity& entity);
    ENTITIES_STATES get_state() final;
    void set_health(int impact_force) final;
    bool is_exist() final;
    bool interact_with_exit(Cell& exit, bool win) const;
    void set_position(int x, int y) final;
    std::pair<int,int> get_position() final;
    int get_killed_enemies() const;
    int get_keys() const;
    friend std::stringstream & operator<<(std::stringstream & out, const Player* obj);
    std::string save() final;
    void load(int xp, int power, int arm, int key, int killed, int pos_x, int pos_y, bool al);
};


#endif //GAME_PLAYER_H
