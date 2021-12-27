#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "Cell/Cell.h"
#include <string>


class Field {
public:
    Field(int w = 20, int h = 20);
    Field(const Field& other);
    Field& operator=(const Field& other);
    Field(Field&& other);
    Field& operator=(Field&& other);
    ~Field();
    void loadField(int h, int w, const std::string& f);
    Cell* get_cell(int x, int y);
    void SetCell(int x, int y, CELL_STATES st);
    void SetObjOnCell(int x, int y, Entity* entity = nullptr);
    int get_width() const;
    int get_height() const;
    std::string save();
private:
    int width;
    int height;
    Cell*** field;
};


#endif //GAME_FIELD_H
