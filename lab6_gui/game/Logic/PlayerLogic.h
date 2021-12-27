#ifndef GAME_PLAYERLOGIC_H
#define GAME_PLAYERLOGIC_H

#include <SFML/Window/Event.hpp>
#include "../Entities/Player.h"
#include "../Field/Field.h"

class PlayerLogic {
private:
    Player* player;
    std::pair<int,int> finish_position;
    bool interactWithCells(Field& field, std::pair<int, int> step, bool win);
    bool is_alive;
public:
    void createPlayer(Field& field);
    bool PlayerExist();
    bool alive() const;
    bool act(Field& field, std::pair<int, int> step, bool win);
    void dellPlayer(Field& field);
    Player* get_player();
    std::string save();
    void load(int xp, int power, int armor, int keys, int killed, int pos_x, int pos_y, bool alive, bool on_f);
    ~PlayerLogic();
};


#endif //GAME_PLAYERLOGIC_H
