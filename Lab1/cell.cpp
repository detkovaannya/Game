#include <iostream>
#include "cell.h"

Cell::Cell(const std::string& filename, sf::Vector2f vec, STATES st, Interface_Object_Cell* ob):
state(st), obj(ob), position(vec){
    texture.loadFromFile(filename);
    sprite = sf::Sprite(texture);
    sprite.setPosition(position.x * SIZE_OF_SPRITE, position.y * SIZE_OF_SPRITE);
}
Cell::Cell(const Cell& other){
    state = other.state;
    texture = other.texture;
    sprite = other.sprite;
    obj = nullptr;
}
Cell& Cell::operator=(const Cell& other){
    if(this != &other){
        state = other.state;
        texture = other.texture;
        sprite = other.sprite;
        obj = nullptr;
    }
    return *this;
}
Cell::Cell(Cell&& other){
    std::swap(state, other.state);
    std::swap(texture, other.texture);
    std::swap(sprite, other.sprite);
    std::swap(obj, other.obj);
}
Cell& Cell::operator=(Cell&& other){
    if(this != &other){
        std::swap(state, other.state);
        std::swap(texture, other.texture);
        std::swap(sprite, other.sprite);
        std::swap(obj, other.obj);
    }
    return *this;
}
void Cell::SetState(STATES st, const std::string& filename) {
    texture.loadFromFile(filename);
    sprite = sf::Sprite(texture);
    sprite.setPosition(position.x * SIZE_OF_SPRITE, position.y * SIZE_OF_SPRITE);
    state = st;
}
int Cell::GetState() {
    return state;
}
bool Cell::IsEmpty() const{
    return (state == 1);
}
bool Cell::IsImpassable() const{
    return (state == 0 || state == 2);
}
sf::Sprite Cell::GetIMG(){
    return sprite;
}
sf::Vector2f Cell::GetPos(){
    return position;
}
/*void Cell::ChangeContent(Interface_Object_Cell* data){
    delete obj;
    obj = data;
}
Interface_Object_Cell* Cell::get_object() {
    return obj;
}*/

