#include <random>
#include <iostream>
#include "Enemy2Logic.h"

void Enemy2Logic::act(Field& field, Player* player) {
    if(player && player->is_exist() && (((enemy2->get_position().first - player->get_position().first == 1 || enemy2->get_position().first - player->get_position().first == -1)
                   && enemy2->get_position().second == player->get_position().second) || ((enemy2->get_position().second - player->get_position().second == 1
                                                                                          || enemy2->get_position().second - player->get_position().second == -1)
                                                                                          && enemy2->get_position().first == player->get_position().first))){
        // если игрок стоит на соседней клетке, то враг атакует
        enemy2->fight(*player);
    } else {
        // иначе, делает ход
        prev_position = enemy2->get_position();
        step++;
        if (step == 10) {
            left = left ^ 1;
            step = 0;
        }
        if (left)
            enemy2->set_position(enemy2->get_position().first - 1, enemy2->get_position().second);
        else
            enemy2->set_position(enemy2->get_position().first + 1, enemy2->get_position().second);
    }
    if (dynamic_cast<Enemy2*>(field.get_cell(prev_position.first, prev_position.second)->Get_Object()))
        dellEntityFromCell(field.get_cell(prev_position.first, prev_position.second));
    if (dynamic_cast<Character*>(field.get_cell(enemy2->get_position().first, enemy2->get_position().second)->Get_Object()))
        dellEntityFromCell(field.get_cell(enemy2->get_position().first, enemy2->get_position().second));
    setEntityOnCell(field.get_cell(enemy2->get_position().first, enemy2->get_position().second));
}

bool Enemy2Logic::entity_exist() {
    return enemy2->is_exist();
}

void Enemy2Logic::createEntity() {
    std::random_device random_device;
    std::mt19937 generator(random_device());

    std::uniform_int_distribution<> distribution(3, 18);
    int rand_y = distribution(generator);
    if (rand_y % 2 == 1)
        rand_y ++;

    enemy2 = new Enemy2(15, rand_y);
    prev_position = {0, 0};
    step = -1;
    left = 1;
    en_alive_and_on_field = true;
}

void Enemy2Logic::setEntityOnCell(Cell *cell) {
    cell->Set_Object(enemy2);
}

void Enemy2Logic::dellEntityFromCell(Cell *cell) {
    cell->Dell_Object();
}

Character * Enemy2Logic::getEntity() {
    return enemy2;
}

Enemy2Logic::~Enemy2Logic() {
    delete enemy2;
}

void Enemy2Logic::removeEntityFromCell(Field& field) {
    en_alive_and_on_field = false;
    dellEntityFromCell(field.get_cell(enemy2->get_position().first, enemy2->get_position().second));
}

bool Enemy2Logic::alive() {
    return en_alive_and_on_field;
}

std::string Enemy2Logic::save() {
    std::string res = enemy2->save();
    res += " " + std::to_string(int(en_alive_and_on_field)) + " " + std::to_string(step) + " " +
            std::to_string(left) + '\n';
    return res;
}

void Enemy2Logic::load(int xp, int att, int arm, int x, int y, bool en_al, bool on_f, int st_x,
                       int direction_x, int st_y, int direction_y) {
    enemy2->load(xp, att, arm, x, y, en_al);
    en_alive_and_on_field = on_f;
    step = st_x;
    left = direction_x;
}
