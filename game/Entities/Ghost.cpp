#include "Ghost.h"

Ghost::Ghost(int x, int y, int heal, int att, int arm): health(heal),
attack(att), armor(arm), state(GHOST), alive(true){
    cur_position.first = x;
    cur_position.second = y;
}

ENTITIES_STATES Ghost::get_state() {
    return state;
}

void Ghost::fight(Player &player) {
    player.set_health(attack);
}

bool Ghost::is_exist() {
    return alive;
}

void Ghost::set_health(int impact_force) {
    if (armor > 0) {
        armor -= impact_force;
        if (armor < 0) {
            health += armor;
            armor = 0;
        }
    } else {
        health -= impact_force;
    }
    if (health <= 0) {
        health = 0;
        alive = false;
        this->notify("Ghost got hit and died.", this);
        return;
    }
    this->notify("Ghost got hit.", this);
}

void Ghost::set_position(int x, int y) {
    cur_position.first = x;
    cur_position.second = y;
}

std::pair<int, int> Ghost::get_position() {
    return cur_position;
}

std::stringstream &operator<<(std::stringstream &out, const Ghost *obj) {
    out << "Ghost\nHealth: " << std::to_string(obj->health) << ".\n";
    return out;
}

std::string Ghost::save() {
    std::string res;
    res = "1 " + std::to_string(health) + " " + std::to_string(attack) + " " + std::to_string(armor) + " " +
            std::to_string(cur_position.first) + " " + std::to_string(cur_position.second) +
            " " + std::to_string(int(alive));
    return res;
}

void Ghost::load(int xp, int att, int arm, int x, int y, bool en_al) {
    health = xp;
    attack = att;
    armor = arm;
    cur_position.first = x;
    cur_position.second = y;
    alive = en_al;
}
