#include <iostream>
#include "PlayerLogic.h"
#include "../Iterator/Iterator.h"

bool PlayerLogic::PlayerExist() {
    return player->is_exist();
}

void PlayerLogic::createPlayer(Field &field) {
    IteratorOfField it(field);
    int x, y;
    for (it.First(); !it.IsDone(); it++) {
        if ((*it)->GetState() == FIN) {
            finish_position.first = it.ret_x();
            finish_position.second = it.ret_y();
        }
        if ((*it)->GetState() == START){
            x = it.ret_x();
            y = it.ret_y();
        }
    }
    player = new Player(x, y);
    field.SetObjOnCell(x, y, player);
    is_alive = true;
}

bool PlayerLogic::act(Field &field, std::pair<int, int> step, bool win) {
    return interactWithCells(field, step, win);
}

bool PlayerLogic::interactWithCells(Field &field, std::pair<int, int> step, bool win) {
    if (!field.get_cell(player->get_position().first + step.first,
                        player->get_position().second + step.second)->IsImpassable()) {

        if (field.get_cell(player->get_position().first + step.first,
                           player->get_position().second + step.second)->Get_Object()) {

            player->interact(*field.get_cell(player->get_position().first + step.first,
                                             player->get_position().second + step.second)->Get_Object());

        }else if (field.get_cell(player->get_position().first + step.first,
                                player->get_position().second + step.second)->GetState() == FIN)

            return player->interact_with_exit(*field.get_cell(player->get_position().first + step.first,
                                    player->get_position().second + step.second), win);

        else {
            field.get_cell(player->get_position().first, player->get_position().second)->Dell_Object();
            player->set_position(player->get_position().first + step.first, player->get_position().second + step.second);
            field.SetObjOnCell(player->get_position().first, player->get_position().second, player);
        }
    }
    return false;
}

Player *PlayerLogic::get_player() {
    return player;
}

PlayerLogic::~PlayerLogic() {
    delete player;
}

void PlayerLogic::dellPlayer(Field &field) {
    is_alive = false;
    field.get_cell(player->get_position().first,player->get_position().second)->Dell_Object();
}

bool PlayerLogic::alive() const {
    return is_alive;
}

std::string PlayerLogic::save() {
    std::string res = player->save();
    res += " " + std::to_string(int(is_alive)) + '\n';
    return res;
}

void PlayerLogic::load(int xp, int power, int armor, int keys, int killed, int pos_x, int pos_y, bool alive, bool on_f) {
    player->load(xp, power, armor, keys, killed, pos_x, pos_y, alive);
    is_alive = on_f;
}
