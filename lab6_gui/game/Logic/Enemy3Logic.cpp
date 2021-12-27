#include <random>
#include "Enemy3Logic.h"
#include "../Iterator/Iterator.h"

void Enemy3Logic::act(Field& field, Player* player) {
    if(player && player->is_exist() && (((enemy3->get_position().first - player->get_position().first == 1 || enemy3->get_position().first - player->get_position().first == -1)
                   && enemy3->get_position().second == player->get_position().second) || ((enemy3->get_position().second - player->get_position().second == 1
                                                                                           || enemy3->get_position().second - player->get_position().second == -1)
                                                                                          && enemy3->get_position().first == player->get_position().first))){
        // если игрок стоит на соседней клетке, то враг атакует
        enemy3->fight(*player);
    } else {
        // иначе, делает ход
        prev_position = enemy3->get_position();

        if (down != -1) // если движемся по-вертикали
            step_y ++;
        else if (left != -1) // если - по-горизонтали
            step_x ++;

        if (left == 1)
            enemy3->set_position(enemy3->get_position().first - 1, enemy3->get_position().second);
        else if (left == 0)
            enemy3->set_position(enemy3->get_position().first + 1, enemy3->get_position().second);
        else if (down == 1)
            enemy3->set_position(enemy3->get_position().first, enemy3->get_position().second + 1);
        else if (down == 0)
            enemy3->set_position(enemy3->get_position().first, enemy3->get_position().second - 1);

        if (step_y == 5 && down != -1)
            down = 0;
        else if (step_y == 11 && down != -1){
            step_y = -1;
            down = -1;
            left = 1;
        } else if (step_x == 5 && left != -1)
            left = 0;
        else if (step_x == 11 && left != -1){
            step_x = -1;
            down = 1;
            left = -1;
        }
    }
    if (dynamic_cast<Enemy3*>(field.get_cell(prev_position.first, prev_position.second)->Get_Object()))
        dellEntityFromCell(field.get_cell(prev_position.first, prev_position.second));
    if (dynamic_cast<Character*>(field.get_cell(enemy3->get_position().first, enemy3->get_position().second)->Get_Object()))
        dellEntityFromCell(field.get_cell(enemy3->get_position().first, enemy3->get_position().second));
    setEntityOnCell(field.get_cell(enemy3->get_position().first, enemy3->get_position().second));
}

bool Enemy3Logic::entity_exist() {
    return enemy3->is_exist();
}

void Enemy3Logic::createEntity() {
    std::random_device random_device;
    std::mt19937 generator(random_device());

    std::uniform_int_distribution<> distribution_x(8, 17);
    int rand_x = distribution_x(generator);

    if (rand_x % 3 == 0)
        rand_x += 2;
    else if (rand_x % 3 == 1)
        rand_x ++;

    std::uniform_int_distribution<> distribution_y(3, 10);
    int rand_y = distribution_y(generator);
    if (rand_y % 2 == 1)
        rand_y ++;

    enemy3 = new Enemy3(rand_x, rand_y);
    prev_position = {0, 0};
    step_x = step_y = -1;
    left = -1;
    down = 1;
    en_alive_and_on_field = true;
}

void Enemy3Logic::setEntityOnCell(Cell *cell) {
    cell->Set_Object(enemy3);
}

void Enemy3Logic::dellEntityFromCell(Cell *cell) {
    cell->Dell_Object();
}

Character* Enemy3Logic::getEntity() {
    return enemy3;
}

Enemy3Logic::~Enemy3Logic() {
    delete enemy3;
}

void Enemy3Logic::removeEntityFromCell(Field& field) {
    en_alive_and_on_field = false;
    dellEntityFromCell(field.get_cell(enemy3->get_position().first, enemy3->get_position().second));
}

bool Enemy3Logic::alive() {
    return en_alive_and_on_field;
}

std::string Enemy3Logic::save() {
    std::string res = enemy3->save();
    res += " " + std::to_string(int(en_alive_and_on_field)) + " " +
            std::to_string(step_y) + " " + std::to_string(down) + " " +
            std::to_string(step_x) + " " + std::to_string(left) + '\n';
    return res;
}

void Enemy3Logic::load(int xp, int att, int arm, int x, int y, bool en_al, bool on_f, int st_x, int direction_x, int st_y, int direction_y) {
    enemy3->load(xp, att, arm, x, y, en_al);
    en_alive_and_on_field = on_f;
    step_x = st_x;
    left = direction_x;
    step_y = st_y;
    down = direction_y;
}
