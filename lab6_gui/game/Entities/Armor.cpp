#include "Armor.h"

Armor::Armor(int x, int y, int prop): property(prop), exist(true), state(ARMOR){
    cur_position.first = x;
    cur_position.second = y;
}

bool Armor::is_exist() {
    return exist;
}

ENTITIES_STATES Armor::get_state() {
    return state;
}

int Armor::take() {
    exist = false;
    return property;
}

void Armor::set_position(int x, int y) {
    cur_position.first = x;
    cur_position.second = y;
}

std::pair<int, int> Armor::get_position() {
    return cur_position;
}

std::string Armor::save() {
    std::string res;
    res = std::to_string(property) + " " + std::to_string(cur_position.first) + " "
            + std::to_string(cur_position.second) + " " + std::to_string(int(exist));
    return res;
}

void Armor::load(int prop, int x, int y, bool taken) {
    property = prop;
    cur_position.first = x;
    cur_position.second = y;
    exist = taken;
}
