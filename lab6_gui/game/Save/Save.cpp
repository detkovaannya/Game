#include <iostream>
#include "Save.h"
#include "../Logic/GhostLogic.h"
#include "../Logic/Enemy2Logic.h"
#include "../Logic/Enemy3Logic.h"

void Save::save(Field &field, PlayerLogic &player, EntityLogic **enemies, int enemies_quantity, ArmorLogic &armor,
                HealLogic &heal, WeaponLogic &weapon, KeyLogic *keys, bool *key_put, bool step) {
    std::ofstream SaveFile;
    SaveFile.open("../game/Save/SaveFile.txt");

    std::string str = field.save();
    str += player.save();
    for (int i = 0; i < 3; i++)
        str += keys[i].save();
    str += armor.save();
    str += weapon.save();
    str += heal.save();
    str += std::to_string(enemies_quantity) + '\n';
    for (int i = 0; i < enemies_quantity; i++)
        str += enemies[i]->save();
    for (int i = 0; i < 3; i++)
        str += std::to_string(int(key_put[i])) + " ";
    str += '\n' + std::to_string(int(step)) + '\n';
    SaveFile << str;
    SaveFile.close();
}

void Save::load(Field &field, PlayerLogic &player, EntityLogic **enemies, int& number, ArmorLogic &armor,
          HealLogic &heal, WeaponLogic &weapon, KeyLogic *keys, bool *key_put, bool& step){
    std::ifstream SaveFile;
    SaveFile.open("../game/Save/SaveFile.txt");
    if (!SaveFile.is_open()) {
        std::cout << "Enable to load save file.\n";
        return;
    }

    // load field
    int h, w;
    SaveFile >> h >> w;
    std::string f;
    SaveFile >> f;
    field.loadField(h, w, f);

    // load player
    int xp, power, arm, key, killed, pos_x, pos_y, p_alive, p_onfield;
    SaveFile >> xp >> power >> arm >> key >> killed >> pos_x >> pos_y >> p_alive >> p_onfield;
    player.load(xp, power, arm, key, killed, pos_x, pos_y, p_alive, p_onfield);
    field.SetObjOnCell(pos_x, pos_y, player.get_player());

    // load objects
    int prop, x, y, taken, put;
    for (int i = 0; i < 3; i++){
        SaveFile >> prop >> x >> y >> taken >> put;
        keys[i].load(prop, x, y, (bool)taken, (bool)put);
    }

    SaveFile >> prop >> x >> y >> taken >> put;
    armor.load(prop, x, y, (bool)taken, (bool)put);
    if (armor.entity_exist())
        armor.put(field);

    SaveFile >> prop >> x >> y >> taken >> put;
    weapon.load(prop, x, y, (bool)taken, (bool)put);
    if (weapon.entity_exist())
        weapon.put(field);

    SaveFile >> prop >> x >> y >> taken >> put;
    heal.load(prop, x, y, (bool)taken, (bool)put);
    if (heal.entity_exist())
        heal.put(field);

//     load enemies
    int n;
    SaveFile >> n;

// delete enemies

    number = n;

    for (int i = 0; i < number; i++){
        int type;
        int hp = 0, pow = 0, armo, x_pos = 0, y_pos, en_al = 0, en_on_f = 0, st_y = 0, d = 0, st_x = 0, l = 0;
        SaveFile >> type;
        switch (type){
            case 1:
                SaveFile >> hp >> pow >> armo >> x_pos >> y_pos >> en_al >> en_on_f >> st_y >> d;
                if (dynamic_cast<Enemy2Logic*>(enemies[i])) {
                    delete dynamic_cast<Enemy2Logic *>(enemies[i]);
                    enemies[i] = new GhostLogic;
                }
                enemies[i]->createEntity();
                enemies[i]->load(hp, pow, armo, x_pos, y_pos, en_al, en_on_f, st_x, l, st_y, d);
                break;
            case 2:
                SaveFile >> hp >> pow >> armo >> x_pos >> y_pos >> en_al >> en_on_f >> st_x >> l;
                if(dynamic_cast<GhostLogic*>(enemies[i])) {
                    delete dynamic_cast<GhostLogic *>(enemies[i]);
                    enemies[i] = new Enemy2Logic;
                }
                enemies[i]->createEntity();
                enemies[i]->load(hp, pow, armo, x_pos, y_pos, en_al, en_on_f, st_x, l, st_y, d);
                break;
            case 3:
                SaveFile >> hp >> pow >> armo >> x_pos >> y_pos >> en_al >> en_on_f >> st_y >> d >> st_x >> l;
                enemies[i]->load(hp, pow, armo, x_pos, y_pos, en_al, en_on_f, st_x, l, st_y, d);
                break;
        }
        if (enemies[i]->entity_exist() && enemies[i]->alive())
            field.SetObjOnCell(enemies[i]->getEntity()->get_position().first, enemies[i]->getEntity()->get_position().second, enemies[i]->getEntity());
    }

    // read bool if key put
    for (int k = 0; k < 3; k++) {
        SaveFile >> key_put[k];
        if (key_put[k] && keys[k].is_put() && keys[k].entity_exist())
            keys[k].put(field);
    }

     // read step
     SaveFile >> step;
}

void Save::dellSave() {
    std::ofstream SaveFile;
    SaveFile.open("../game/Save/SaveFile.txt");
    SaveFile << "";
    SaveFile.close();
}

bool Save::tryLoad() {
    std::ifstream SaveFile;
    SaveFile.open("../game/Save/SaveFile.txt");
    if (!SaveFile.is_open()) {
        std::cout << "Enable to load save file.\n";
        return false;
    }
    std::string str;
    int k = 0;
    while (!SaveFile.eof()){
        getline(SaveFile, str);
        k ++;
    }
    if (k < 17){
        SaveFile.close();
        std::cout << "Save file incorrect: there isn't saving or saving is not correct.\n";
        return false;
    }

    SaveFile.close();
    return true;
}
