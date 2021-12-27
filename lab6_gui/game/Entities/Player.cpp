#include <iostream>
#include "Player.h"

Player::Player(int x, int y, int heal, int att): health(heal), attack(att),
armor(0), keys(0), state(PLAYER), alive(true), killed_enemies(0){
    cur_position.first = x;
    cur_position.second = y;
}

ENTITIES_STATES Player::get_state() {
    return state;
}

void Player::interact(Entity &entity) {
    switch (entity.get_state()) {
        case GHOST:
        case ENEMY2:
        case ENEMY3:
            (dynamic_cast<Character&> (entity)).set_health(attack);
            if(!(dynamic_cast<Character&> (entity)).is_exist())
                killed_enemies ++;
            break;
        case KEY:
            if (dynamic_cast<Object&> (entity).is_exist()) {
                keys += (dynamic_cast<Object &> (entity)).take();
                this->notify("Player took key.", this);
            }
            break;
        case HEAL:
            if (dynamic_cast<Object&> (entity).is_exist()) {
                health += (dynamic_cast<Object &> (entity)).take();
                this->notify("Player took heal.", this);
            }
            break;
        case WEAPON:
            if (dynamic_cast<Object&> (entity).is_exist()) {
                attack += (dynamic_cast<Object &> (entity)).take();
                this->notify("Player took weapon.", this);
            }
            break;
        case ARMOR:
            if (dynamic_cast<Object&> (entity).is_exist()) {
                armor += (dynamic_cast<Object &> (entity)).take();
                this->notify("Player took armor.", this);
            }
            break;
        case PLAYER:
            break;
    }
}

void Player::set_health(int impact_force) {
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
        alive = false;
        this->notify("Player got hit and died.", this);
        return;
    }
    this->notify("Player got hit.", this);
}

bool Player::is_exist() {
    return alive;
}

bool Player::interact_with_exit(Cell &exit, bool win) const {
    if (win)
        return true;
    return false;
}

void Player::set_position(int x, int y) {
    cur_position.first = x;
    cur_position.second = y;
}

std::pair<int, int> Player::get_position() {
    return cur_position;
}

std::stringstream &operator<<(std::stringstream &out, const Player *obj) {
    out << "Player\nHealth: " << std::to_string(obj->health) << "; attack: " << std::to_string(obj->attack) <<
    "; armor: " << std::to_string(obj->armor) << "; keys: " << std::to_string(obj->keys) <<
    "; quantity of killed enemies: " << std::to_string(obj->killed_enemies) << ".\n";
    return out;
}

int Player::get_keys() const {
    return keys;
}

int Player::get_killed_enemies() const {
    return killed_enemies;
}

std::string Player::save() {
    std::string res;
    res += std::to_string(health) + " " + std::to_string(attack) + " " + std::to_string(armor) + " " +
            std::to_string(keys) + " " + std::to_string(killed_enemies) + " " +
            std::to_string(cur_position.first) + " " + std::to_string(cur_position.second) +
            " " + std::to_string(int(alive));
    return res;
}

void Player::load(int xp, int power, int arm, int key, int killed, int pos_x, int pos_y, bool al) {
    health = xp;
    attack = power;
    armor = arm;
    keys = key;
    killed_enemies = killed;
    cur_position.first = pos_x;
    cur_position.second = pos_y;
    alive = al;
}
