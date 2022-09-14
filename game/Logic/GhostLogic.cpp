#include <random>
#include "GhostLogic.h"

void GhostLogic::act(Field& field, Player* player) {

    if(player && player->is_exist() && ((abs(ghost->get_position().first - player->get_position().first) == 1 &&
    ghost->get_position().second == player->get_position().second) ||
    (abs(ghost->get_position().second - player->get_position().second) == 1
    && ghost->get_position().first == player->get_position().first))){
        // если игрок стоит на соседней клетке, то враг атакует
        ghost->fight(*player);
    } else {
        // иначе, делает ход
        prev_position = ghost->get_position();
        step++;
        if (step == 13) {
            down = down ^ 1;
            step = 0;
        }
        if (down)
            ghost->set_position(ghost->get_position().first, ghost->get_position().second + 1);
        else
            ghost->set_position(ghost->get_position().first, ghost->get_position().second - 1);
    }
    if (dynamic_cast<Ghost*>(field.get_cell(prev_position.first, prev_position.second)->Get_Object()))
        dellEntityFromCell(field.get_cell(prev_position.first, prev_position.second));
    if (dynamic_cast<Character*>(field.get_cell(ghost->get_position().first, ghost->get_position().second)->Get_Object()))
        dellEntityFromCell(field.get_cell(ghost->get_position().first, ghost->get_position().second));
    setEntityOnCell(field.get_cell(ghost->get_position().first, ghost->get_position().second));
}

bool GhostLogic::entity_exist() {
    return ghost->is_exist();
}

void GhostLogic::createEntity() {
    std::random_device random_device;
    std::mt19937 generator(random_device());

    std::uniform_int_distribution<> distribution1(2, 17);
    int rand_x = distribution1(generator);

    if (rand_x % 3 == 0)
        rand_x += 2;
    else if (rand_x % 3 == 1)
        rand_x ++;

    ghost = new Ghost(rand_x, 3);
    prev_position = {0, 0};
    step = -1;
    down = 1;
    en_alive_and_on_field = true;
}

void GhostLogic::setEntityOnCell(Cell *cell) {
    cell->Set_Object(ghost);
}

void GhostLogic::dellEntityFromCell(Cell *cell) {

    cell->Dell_Object();
}

Character * GhostLogic::getEntity() {
    return ghost;
}

GhostLogic::~GhostLogic() {
    delete ghost;
}

void GhostLogic::removeEntityFromCell(Field& field) {
    en_alive_and_on_field = false;
    dellEntityFromCell(field.get_cell(ghost->get_position().first, ghost->get_position().second));
}

bool GhostLogic::alive() {
    return en_alive_and_on_field;
}

std::string GhostLogic::save() {
    std::string res = ghost->save();
    res += " " + std::to_string(int(en_alive_and_on_field)) + " " +
            std::to_string(step) + " " + std::to_string(down) + "\n";
    return res;
}

void GhostLogic::load(int xp, int att, int arm, int x, int y, bool en_al, bool on_f, int st_x,
                           int direction_x, int st_y, int direction_y){
    ghost->load(xp, att, arm, x, y, en_al);
    en_alive_and_on_field = on_f;
    step = st_y;
    down = direction_y;
}
