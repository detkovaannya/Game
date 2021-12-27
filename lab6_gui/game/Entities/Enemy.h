#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "Player.h"
#include "Character.h"

class Enemy: public Character{
public:
    Enemy() = default;
    virtual void fight(Player& player) = 0;
};


#endif //GAME_ENEMY_H
