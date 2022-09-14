#include "Weapon.h"

Weapon::Weapon(int x, int y, int prop): property(prop), exist(true), state(WEAPON){
    cur_position.first = x;
    cur_position.second = y;
}

bool Weapon::is_exist() {
    return exist;
}

ENTITIES_STATES Weapon::get_state() {
    return state;
}

int Weapon::take() {
    exist = false;
    return property;
}

void Weapon::set_position(int x, int y) {
    cur_position.first = x;
    cur_position.second = y;
}

std::pair<int, int> Weapon::get_position() {
    return cur_position;
}

std::string Weapon::save() {
    std::string res;
    res = std::to_string(property) + " " + std::to_string(cur_position.first) + " "
          + std::to_string(cur_position.second) + " " + std::to_string(int(exist));
    return res;
}

void Weapon::load(int prop, int x, int y, bool taken) {
    property = prop;
    cur_position.first = x;
    cur_position.second = y;
    exist = taken;
}
