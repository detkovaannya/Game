#ifndef GAME_CELL_H
#define GAME_CELL_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Interface_Object_Cell.h"
#define SIZE_OF_SPRITE 40
#define PATH_TO_BOARD_IMG "/home/anna/CLionProjects/game/wall.png"
#define PATH_TO_EMPTY_CELL "/home/anna/CLionProjects/game/grass.png"
#define PATH_TO_START_CELL "/home/anna/CLionProjects/game/start.png"
#define PATH_TO_END_CELL "/home/anna/CLionProjects/game/start.png"

/*
 * IMP - 0 - impassable
 * EMP - 1 - empty
 * SPEC - 2 - special
 * START - 3 - start
 * FIN - 4 - finish
 */

enum STATES {IMP = 0, EMP, SPEC, START, FIN};

class Cell{
public:
    Cell(const std::string& filename, sf::Vector2f vec, STATES st = IMP, Interface_Object_Cell* ob = nullptr);
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    Cell(Cell&& other);
    Cell& operator=(Cell&& other);
    void SetState(STATES st, const std::string& filename);
    int GetState();
    bool IsEmpty() const;
    bool IsImpassable() const;
    sf::Sprite GetIMG();
    sf::Vector2f GetPos();
    /*void ChangeContent(Interface_Object_Cell* data);
    Interface_Object_Cell* get_object();*/
private:
    Interface_Object_Cell* obj;
    int state;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;
};


#endif //GAME_CELL_H
