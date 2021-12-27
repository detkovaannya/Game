#include "ArmorLogic.h"

void ArmorLogic::put(Field &field) { // если клетка, где должен находиться объект, пуста
    // то устанавливаем объект
    setEntityOnCell(field.get_cell(armor->get_position().first,
                                       armor->get_position().second));
}

bool ArmorLogic::entity_exist() {
    return armor->is_exist();
}

void ArmorLogic::createEntity() {

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

    armor = new Armor(rand_x,rand_y);
    isPut = true;
}

void ArmorLogic::setEntityOnCell(Cell *cell) {
    cell->Set_Object(armor);
}

ArmorLogic::~ArmorLogic() {
    delete armor;
}

Object *ArmorLogic::getObject() {
    return armor;
}

void ArmorLogic::take(Field &field) {
    isPut = false;
    field.get_cell(armor->get_position().first, armor->get_position().second)->Dell_Object();
}

bool ArmorLogic::is_put() {
    return isPut;
}

std::string ArmorLogic::save() {
    std::string res = armor->save();
    res += " " + std::to_string(int(isPut)) + '\n';
    return res;
}

void ArmorLogic::load(int prop, int x, int y, bool taken, bool put) {
    armor->load(prop, x, y, taken);
    isPut = put;
}
