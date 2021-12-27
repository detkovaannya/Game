#include <iostream>
#include "KeyLogic.h"

void KeyLogic::put(Field &field) { // если клетка, где должен находиться объект, пуста
    // то устанавливаем объект
    if (field.get_cell(key->get_position().first,
                       key->get_position().second)->Get_Object() == nullptr)
        setEntityOnCell(field.get_cell(key->get_position().first,
                                   key->get_position().second));
}

bool KeyLogic::entity_exist() {
    return key->is_exist();
}

void KeyLogic::createEntity() {

    std::random_device random_device;
    std::mt19937 generator(random_device());

    std::uniform_int_distribution<> distribution1(2, 17);
    int rand_x = distribution1(generator);

    if (rand_x % 3 == 0)
        rand_x += 2;
    else if (rand_x % 3 == 1)
        rand_x ++;

    std::uniform_int_distribution<> distribution2(3, 18);
    int rand_y = distribution2(generator);
    if (rand_y % 2 == 1)
        rand_y ++;

    key = new Key(rand_x,rand_y);
    isPut = true;
}

void KeyLogic::setEntityOnCell(Cell *cell) {
    cell->Set_Object(key);
}

KeyLogic::~KeyLogic() {
    delete key;
}

Object *KeyLogic::getObject() {
    return key;
}

void KeyLogic::take(Field &field) {
    isPut = false;
    field.get_cell(key->get_position().first, key->get_position().second)->Dell_Object();
}

bool KeyLogic::is_put() {
    return isPut;
}

std::string KeyLogic::save() {
    std::string res = key->save();
    res += " " + std::to_string(int(isPut)) + '\n';
    return res;
}

void KeyLogic::load(int prop, int x, int y, bool taken, bool put) {
    key->load(prop, x, y, taken);
    isPut = put;
}
