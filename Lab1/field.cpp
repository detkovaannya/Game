#include <iostream>
#include "field.h"


Field::Field(int w, int h): width(w), height(h), field(new Cell** [height]){
    for (int i=0; i<height; i++){
        field[i] = new Cell* [width];
        for(int j=0; j<width; j++)
            field[i][j] = new Cell(PATH_TO_BOARD_IMG,sf::Vector2f((float)j,(float)i));
    }
}
Field::Field(const Field& other): width(other.width), height(other.height), field(new Cell** [height]){
    for (int i=0; i<height; i++){
        field[i] =  new Cell* [width];
        for(int j=0; j<width; j++) {
            field[i][j] = new Cell("/home/anna/CLionProjects/game/bush_PNG7202.png",
                                   sf::Vector2f((float)j,(float)i));
            *(field[i][j]) = *(other.field[i][j]);
        }
    }
}
Field& Field::operator=(const Field& other){
    if(this != &other){
        width = other.width;
        height = other.height;

        for(int i = 0; i<height; i++){
            for (int j=0; j<width; j++)
                delete field[i][j];
            delete[] field[i];
        }
        delete[] field;

        field = new Cell** [height];
        for (int i=0; i<height; i++){
            field[i] =  new Cell* [width];
            for(int j=0; j<width; j++) {
                field[i][j] = new Cell("/home/anna/CLionProjects/game/bush_PNG7202.png",
                                       sf::Vector2f((float)j,(float)i));
                *(field[i][j]) = *(other.field[i][j]);
            }
        }
    }
    return *this;
}
Field::Field(Field&& other){
    std::swap(width, other.width);
    std::swap(height, other.height);
    std::swap(field, other.field);
}
Field& Field::operator=(Field&& other){
    if(this != &other){
        std::swap(width, other.width);
        std::swap(height, other.height);
        std::swap(field, other.field);
    }
    return *this;
}
Field::~Field(){
    for(int i = 0; i<height; i++){
        for (int j=0; j<width; j++)
            delete field[i][j];
        delete[] field[i];
    }
    delete[] field;
}
Cell* Field::get_cell(int x, int y){
    return field[y][x];
}
void Field::SetCell(int x, int y, STATES st, std::string& filepath) {
    field[y][x]->SetState(st, filepath);
}
int Field::get_width(){
    return width;
}
int Field::get_height(){
    return height;
}
