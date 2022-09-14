#ifndef GAME_DRAWENTITIES_H
#define GAME_DRAWENTITIES_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Field/Cell/Cell.h"

#define SIZE_OF_SPRITE 40
#define PATH_TO_GHOST "/home/anna/CLionProjects/game/game/Pictures/enemy1.png"
#define PATH_TO_PLAYER "/home/anna/CLionProjects/game/game/Pictures/player.png"
#define PATH_TO_ENEMY2 "/home/anna/CLionProjects/game/game/Pictures/enemy2.png"
#define PATH_TO_ENEMY3 "/home/anna/CLionProjects/game/game/Pictures/enemy3.png"
#define PATH_TO_ARMOR "/home/anna/CLionProjects/game/game/Pictures/armor.png"
#define PATH_TO_HEAL "/home/anna/CLionProjects/game/game/Pictures/heal.png"
#define PATH_TO_KEY "/home/anna/CLionProjects/game/game/Pictures/key.png"
#define PATH_TO_WEAPON "/home/anna/CLionProjects/game/game/Pictures/weapon.png"


class DrawEntities {
private:
    std::string types[8];
    sf::Texture textures[8];
    sf::Sprite sprite;
public:
    DrawEntities();
    void Draw_Object(sf::RenderWindow& window, const std::string& type, int x, int y);
};


#endif //GAME_DRAWENTITIES_H
