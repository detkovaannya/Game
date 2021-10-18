#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "cell.h"

#define  WIDTH 100
#define HEIGHT 20


class Field {
public:
    Field();
    Field(const Field& other);
    Field& operator=(const Field& other);
    Field(Field&& other);
    Field& operator=(Field&& other);
    ~Field();
    Cell*** get_field();
    int get_width();
    int get_height();
    void print_field();
private:
    int width;
    int height;
    Cell*** field;
};


#endif //GAME_FIELD_H
