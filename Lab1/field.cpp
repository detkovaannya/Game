#include <iostream>
#include "field.h"

Field::Field(): width(WIDTH), height(HEIGHT){
    field = new Cell** [height];
    for (int i=0; i<height; i++){
        field[i] = new Cell* [width];
        for(int j=0; j<width; j++)
            if (j == width - 1)
                field[i][j] = new Cell('\n');
            else
                field[i][j] = new Cell('#');
    }
}
Field::Field(const Field& other): width(other.width), height(other.height){
    field = new Cell** [height];
    for (int i=0; i<height; i++){
        field[i] = new Cell* [width];
        for(int j=0; j<width; j++)
            field[i][j] = new Cell(other.field[i][j]->get_content());
    }
}
Field& Field::operator=(const Field& other){
    if(this != &other){
        width = other.width;
        height = other.height;

        for (int i=0; i<height; i++) {
            for (int j = 0; j < width; j++)
                delete[] field[i][j];
            delete[] field[i];
        }
        delete[] field;

        field = new Cell** [height];
        for (int i=0; i<height; i++){
            field[i] = new Cell* [width];
            for(int j=0; j<width; j++)
                field[i][j] = new Cell(other.field[i][j]->get_content());
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
    for (int i=0; i<height; i++) {
        for (int j = 0; j < width; j++)
            delete[] field[i][j];
        delete[] field[i];
    }
    delete[] field;
}
Cell*** Field::get_field(){
    return field;
}
int Field::get_width(){
    return width;
}
int Field::get_height(){
    return height;
}
void Field::print_field() {
    for (int i=0; i<height; i++){
        for(int j=0; j<width; j++)
            std::cout << field[i][j]->get_content();
    }
}
