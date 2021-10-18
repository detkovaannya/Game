#ifndef GAME_CELL_H
#define GAME_CELL_H

#include "ICell.h"

class Cell: public ICell{
public:
    explicit Cell(char data);
    void change_content(char c) final;
    char get_content() final;
    bool IsEmpty() final;
private:
    char content;
    char state;
};


#endif //GAME_CELL_H
