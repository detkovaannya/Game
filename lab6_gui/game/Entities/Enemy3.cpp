#include "Enemy3.h"

Enemy3::Enemy3(int x, int y, int heal, int att, int arm): health(heal),
attack(att), armor(arm), state(ENEMY3), alive(true){
    cur_position.first = x;
    cur_position.second = y;
}

ENTITIES_STATES Enemy3::get_state() {
    return state;
}

bool Enemy3::is_exist() {
    return alive;
}

void Enemy3::fight(Player &player) {
    player.set_health(attack);
}

void Enemy3::set_health(int impact_force) {
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
        this->notify("Enemy3 got hit and died.", this);
        return;
    }
    this->notify("Enemy3 got hit.", this);
}

void Enemy3::set_position(int x, int y) {
    cur_position.first = x;
    cur_position.second = y;
}

std::pair<int, int> Enemy3::get_position() {
    return cur_position;
}

std::stringstream &operator<<(std::stringstream &out, const Enemy3 *obj) {
    out << "Enemy2\nHealth: " << std::to_string(obj->health) << ".\n";
    return out;
}

std::string Enemy3::save() {
    std::string res;
    res = "3 " + std::to_string(health) + " " + std::to_string(attack) + " " + std::to_string(armor) + " " +
          std::to_string(cur_position.first) + " " + std::to_string(cur_position.second) +
          " " + std::to_string(int(alive));
    return res;
}

void Enemy3::load(int xp, int att, int arm, int x, int y, bool en_al) {
    health = xp;
    attack = att;
    armor = arm;
    cur_position.first = x;
    cur_position.second = y;
    alive = en_al;
}
