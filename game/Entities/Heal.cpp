#include "Heal.h"

Heal::Heal(int x, int y, int prop): property(prop), exist(true), state(HEAL){
    cur_position.first = x;
    cur_position.second = y;
}

bool Heal::is_exist() {
    return exist;
}

ENTITIES_STATES Heal::get_state() {
    return state;
}

int Heal::take() {
    exist = false;
    return property;
}


void Heal::set_position(int x, int y) {
    cur_position.first = x;
    cur_position.second = y;
}

std::pair<int, int> Heal::get_position() {
    return cur_position;
}

std::string Heal::save() {
    std::string res;
    res = std::to_string(property) + " " + std::to_string(cur_position.first) + " "
          + std::to_string(cur_position.second) + " " + std::to_string(int(exist));
    return res;
}

void Heal::load(int prop, int x, int y, bool taken) {
    property = prop;
    cur_position.first = x;
    cur_position.second = y;
    exist = taken;
}
