#include <iostream>
#include "Field.h"


Field::Field(int w, int h): width(w), height(h), field(new Cell** [height]){
    for (int i=0; i<height; i++){
        field[i] = new Cell* [width];
        for(int j=0; j<width; j++)
            field[i][j] = new Cell();
    }
}
Field::Field(const Field& other): width(other.width), height(other.height), field(new Cell** [height]){
    for (int i=0; i<height; i++){
        field[i] =  new Cell* [width];
        for(int j=0; j<width; j++) {
            field[i][j] = new Cell();
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
                field[i][j] = new Cell();
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
void Field::SetCell(int x, int y, CELL_STATES st) {
    field[y][x]->SetState(st);
}
int Field::get_width() const{
    return width;
}
int Field::get_height() const{
    return height;
}

void Field::SetObjOnCell(int x, int y, Entity *entity) {
    field[y][x]->Set_Object(entity);
}

std::string Field::save() {
    std::string res;
    res = std::to_string(height) + " " + std::to_string(width) + "\n";
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            res += std::to_string(get_cell(j, i)->GetState());
    res += '\n';
    return res;
}

void Field::loadField(int h, int w, const std::string& f) {
    height = h;
    width = w;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            SetObjOnCell(j, i, nullptr);
            switch (f[height * i + j]) {
                case '0':
                    SetCell(j, i, IMP);
                    break;
                case '1':
                    SetCell(j, i, EMP);
                    break;
                case '2':
                    SetCell(j, i, START);
                    break;
                case '3':
                    SetCell(j, i, FIN);
                    break;
            }
    }
}
