#ifndef GAME_ICELL_H
#define GAME_ICELL_H


class Interface_Object_Cell {
public:
    virtual void interact() = 0;
    virtual char get_content() = 0;
    virtual void move_logic() = 0;
    virtual ~Interface_Object_Cell() = 0;
};


#endif //GAME_ICELL_H
