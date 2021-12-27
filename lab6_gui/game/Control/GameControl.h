#ifndef GAME_GAMECONTROL_H
#define GAME_GAMECONTROL_H


#include <utility>
#include <SFML/Window/Keyboard.hpp>

class GameControl {
private:
    std::pair<int, int> step; // first - x; second - y
    sf::Keyboard::Key right, left, up, down, save, load;
public:
    GameControl(sf::Keyboard::Key r = sf::Keyboard::Right, sf::Keyboard::Key l = sf::Keyboard::Left,
                sf::Keyboard::Key u = sf::Keyboard::Up, sf::Keyboard::Key d = sf::Keyboard::Down,
                sf::Keyboard::Key s = sf::Keyboard::Enter, sf::Keyboard::Key ld = sf::Keyboard::Escape);
    std::pair<int, int> control();
};


#endif //GAME_GAMECONTROL_H
