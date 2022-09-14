#ifndef GAME_RULEFORENEMY_H
#define GAME_RULEFORENEMY_H


#include <random>
#include "../Logic/EntityLogic.h"
#include "../Logic/Enemy3Logic.h"
#include "../Logic/Enemy2Logic.h"
#include "../Logic/GhostLogic.h"

template<int quantity>
class RuleForEnemy{
private:
    int numder = quantity;
public:
    EntityLogic** MakeRuleEnemies(){
        auto** enemies = new EntityLogic*[quantity];
        int index = 0;
        enemies[index] = new Enemy3Logic;
        enemies[index]->createEntity();
        index ++;
        for (index; index < quantity; index ++){
            std::random_device random_device;
            std::mt19937 generator(random_device());
            std::uniform_int_distribution<> distribution(0, 20);
            int rand = distribution(generator);
            if (rand % 2 == 0)
                enemies[index] = new GhostLogic;
            else
                enemies[index] = new Enemy2Logic;
            enemies[index]->createEntity();
        }
        return enemies;
    }
    int Get_Quantity(){
        return numder;
    }
    void Set_Quantity(int numb){
        numder = numb;
    }
};


#endif //GAME_RULEFORENEMY_H
