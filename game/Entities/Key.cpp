#include "Key.h"

Key::Key(int x, int y, int prop): property(prop), exist(true), state(KEY){
    cur_position.first = x;
    cur_position.second = y;
}

bool Key::is_exist() {
    return exist;
}

ENTITIES_STATES Key::get_state() {
    return state;
}

int Key::take() {
    exist = false;
    return property;
}

void Key::set_position(int x, int y) {
    cur_position.first = x;
    cur_position.second = y;
}

std::pair<int, int> Key::get_position() {
    return cur_position;
}

std::string Key::save() {
    std::string res;
    res = std::to_string(property) + " " + std::to_string(cur_position.first) + " "
          + std::to_string(cur_position.second) + " " + std::to_string(int(exist));
    return res;
}

void Key::load(int prop, int x, int y, bool taken) {
    property = prop;
    cur_position.first = x;
    cur_position.second = y;
    exist = taken;
}
