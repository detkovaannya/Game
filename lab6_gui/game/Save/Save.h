#ifndef GAME_SAVE_H
#define GAME_SAVE_H


#include "../Field/Field.h"
#include "../Logic/PlayerLogic.h"
#include "../Logic/EntityLogic.h"
#include "../Logic/ArmorLogic.h"
#include "../Logic/HealLogic.h"
#include "../Logic/WeaponLogic.h"
#include "../Logic/KeyLogic.h"

class Save {
public:
    void save(Field& field, PlayerLogic& player, EntityLogic** enemies, int enemies_quantity,
              ArmorLogic& armor, HealLogic& heal, WeaponLogic& weapon, KeyLogic* keys, bool* key_put, bool step);

    void load(Field &field, PlayerLogic &player, EntityLogic **enemies, int& number, ArmorLogic &armor,
         HealLogic &heal, WeaponLogic &weapon, KeyLogic *keys, bool *key_put, bool& step);
    void dellSave();
    bool tryLoad();
};


#endif //GAME_SAVE_H
