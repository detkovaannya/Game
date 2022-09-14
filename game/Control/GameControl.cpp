#include "GameControl.h"

GameControl::GameControl(sf::Keyboard::Key r, sf::Keyboard::Key l, sf::Keyboard::Key u, sf::Keyboard::Key d,
                         sf::Keyboard::Key s, sf::Keyboard::Key ld):
                         right(r), left(l), up(u), down(d), save(s), load(ld){}

std::pair<int, int> GameControl::control() {
    bool key_pressed = false;
    while(!key_pressed){
        if (sf::Keyboard::isKeyPressed(right)){
            key_pressed = true;
            step = {1, 0};
        } else if (sf::Keyboard::isKeyPressed(left)) {
            key_pressed = true;
            step = {-1, 0};
        } else if (sf::Keyboard::isKeyPressed(up)) {
            key_pressed = true;
            step = {0, -1};
        } else if (sf::Keyboard::isKeyPressed(down)) {
            key_pressed = true;
            step = {0, 1};
        } else if (sf::Keyboard::isKeyPressed(save)) {
            key_pressed = true;
            step = {0,0};
        } else if (sf::Keyboard::isKeyPressed(load)){
            key_pressed = true;
            step = {-1, -1};
        }
    }
    return step;
}