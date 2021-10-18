#ifndef GAME_ICELL_H
#define GAME_ICELL_H


class ICell {
    virtual void change_content(char c) = 0;
    virtual char get_content() = 0;
    virtual bool IsEmpty() = 0;
};


#endif //GAME_ICELL_H
