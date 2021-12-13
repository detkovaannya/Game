#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "cell.h"

class Field {
public:
    Field(int w = 20, int h = 20);
    Field(const Field& other);
    Field& operator=(const Field& other);
    Field(Field&& other);
    Field& operator=(Field&& other);
    ~Field();
    Cell* get_cell(int x, int y);// |+| не возвращать указатель на поле, лучше отдавать отедльную клетку
    void SetCell(int x, int y, STATES st, std::string& filepath);
    int get_width();
    int get_height();
    //  |+| сделать setCell, сделать параметрический размер поля
private:
    int width;
    int height;
    Cell*** field;
};


#endif //GAME_FIELD_H
