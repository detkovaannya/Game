#ifndef GAME_DRAWFIELD_H
#define GAME_DRAWFIELD_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Field/Cell/Cell.h"

#define SIZE_OF_SPRITE 40
#define PATH_TO_BOARD_IMG "/home/anna/CLionProjects/game/game/Pictures/wall.png"
#define PATH_TO_EMPTY_CELL "/home/anna/CLionProjects/game/game/Pictures/grass.png"
#define PATH_TO_START_CELL "/home/anna/CLionProjects/game/game/Pictures/start.png"
#define PATH_TO_END_CELL "/home/anna/CLionProjects/game/game/Pictures/start.png"


class DrawField {
private:
    sf::Texture TexturesArray[4];
    sf::Sprite sprite;
public:
    DrawField();
    void Draw_Object(sf::RenderWindow& window, CELL_STATES type, int x, int y);
};


#endif //GAME_DRAWFIELD_H
