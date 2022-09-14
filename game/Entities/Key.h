#ifndef GAME_KEY_H
#define GAME_KEY_H

#include "Object.h"

class Key: public Object{
public:
    Key() = default;
    Key(int x, int y, int prop = 1);
    ENTITIES_STATES get_state() final;
    bool is_exist() final;
    int take() final;
    void set_position(int x, int y) final;
    std::pair<int,int> get_position() final;
    std::string save() final;
    void load(int prop, int x, int y, bool taken) final;
private:
    int property;
    std::pair<int, int> cur_position; // позиция на поле: x и y
    ENTITIES_STATES state; // тип, нужен для отрисовки и узнавания
    bool exist;
};


#endif //GAME_KEY_H
