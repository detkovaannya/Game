#include "HealLogic.h"

void HealLogic::put(Field &field) { // если клетка, где должен находиться объект, пуста
    // то устанавливаем объект
    if (field.get_cell(heal->get_position().first,
                       heal->get_position().second)->Get_Object() == nullptr)
        setEntityOnCell(field.get_cell(heal->get_position().first,
                                       heal->get_position().second));
}

bool HealLogic::entity_exist() {
    return heal->is_exist();
}

void HealLogic::createEntity() {

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

    heal = new Heal(rand_x,rand_y);
    isPut = true;
}

void HealLogic::setEntityOnCell(Cell *cell) {
    cell->Set_Object(heal);
}

HealLogic::~HealLogic() {
    delete heal;
}

Object *HealLogic::getObject() {
    return heal;
}

void HealLogic::take(Field &field) {
    isPut = false;
    field.get_cell(heal->get_position().first, heal->get_position().second)->Dell_Object();
}

bool HealLogic::is_put() {
    return isPut;
}

std::string HealLogic::save() {
    std::string res = heal->save();
    res += " " + std::to_string(int(isPut)) + '\n';
    return res;
}

void HealLogic::load(int prop, int x, int y, bool taken, bool put) {
    heal->load(prop, x, y, taken);
    isPut = put;
}
