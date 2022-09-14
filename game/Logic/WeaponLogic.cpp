#include "WeaponLogic.h"

void WeaponLogic::put(Field &field) { // если клетка, где должен находиться объект, пуста
    // то устанавливаем объект
    if (field.get_cell(weapon->get_position().first,
                       weapon->get_position().second)->Get_Object() == nullptr)
        setEntityOnCell(field.get_cell(weapon->get_position().first,
                                       weapon->get_position().second));
}

bool WeaponLogic::entity_exist() {
    return weapon->is_exist();
}

void WeaponLogic::createEntity() {

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

    weapon = new Weapon(rand_x,rand_y);
    isPut = true;
}

void WeaponLogic::setEntityOnCell(Cell *cell) {
    cell->Set_Object(weapon);
}

WeaponLogic::~WeaponLogic() {
    delete weapon;
}

Object *WeaponLogic::getObject() {
    return weapon;
}

void WeaponLogic::take(Field &field) {
    isPut = false;
    field.get_cell(weapon->get_position().first, weapon->get_position().second)->Dell_Object();
}

bool WeaponLogic::is_put() {
    return isPut;
}

std::string WeaponLogic::save() {
    std::string res = weapon->save();
    res += " " + std::to_string(int(isPut)) + '\n';
    return res;
}

void WeaponLogic::load(int prop, int x, int y, bool taken, bool put) {
    weapon->load(prop, x, y, taken);
    isPut = put;
}
