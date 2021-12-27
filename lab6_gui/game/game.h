#ifndef GAME_GAME_H
#define GAME_GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Sleep.hpp>

#include "Builder/Director.h"
#include "Drawers/DrawField.h"
#include "Logic/KeyLogic.h"
#include "Logic/GhostLogic.h"
#include "Logic/Enemy2Logic.h"
#include "Logic/Enemy3Logic.h"
#include "Logic/PlayerLogic.h"
#include "Logic/ArmorLogic.h"
#include "Logic/HealLogic.h"
#include "Logic/WeaponLogic.h"
#include "Drawers/DrawEntities.h"
#include "Control/GameControl.h"
#include "Save/Save.h"

template <class T1, class T2, class T3>
class Game {
private:
    Field field;
    EntityLogic** enemies; // массив врагов
    PlayerLogic player; //player
    ArmorLogic armor; //armor
    HealLogic heal; //heal
    WeaponLogic weapon; //weapon
    KeyLogic keys[3];
    bool* k_put;
public:
    void GameStart(){

        std::cout << "Game control: Up - move up, Down - move down, Left - move Left, Right - move right\n"
                     "Space - save game, Esc - load game in eb=very moment of game\n";

        T2 builder;
        sf::RenderWindow window(sf::VideoMode(builder.GetSizeOfWindow() * SIZE_OF_SPRITE, builder.GetSizeOfWindow() * SIZE_OF_SPRITE), "game");
        field = *(builder.GenerateFieldWithRuledSize());

        Save saver;

        DrawField fieldDrawer; // отрисовщики поля и сущностей
        DrawEntities entitiesDrawer;

        T1 enemiesCreator; // создатель врагов
        enemies = enemiesCreator.MakeRuleEnemies();

        T3 condToWin;

        // make player and objects
        player.createPlayer(field);
        armor.createEntity();
        armor.put(field);
        heal.createEntity();
        heal.put(field);
        weapon.createEntity();
        weapon.put(field);
        for (auto & key : keys)
            key.createEntity();

        SetLogger logger;
        player.get_player()->setObserver(&logger);

        for (int i = 0; i < enemiesCreator.Get_Quantity(); i++){
            enemies[i]->getEntity()->setObserver(&logger);
        }

        k_put = new bool[3];
        for (int i = 0; i < 3; i++)
            k_put[i] = false;

        bool player_step = false;

        std::cout << "You can load last save. Input 1 for this, else input other symbol.\n";
        int cmd;
        std::cin >> cmd;
        if (cmd == 1){
            int number = enemiesCreator.Get_Quantity();
            if(saver.tryLoad()){
                saver.load(field, player, enemies, number, armor, heal, weapon, keys, k_put, player_step);
                enemiesCreator.Set_Quantity(number);
                for (int i = 0; i < enemiesCreator.Get_Quantity(); i++){
                    enemies[i]->getEntity()->setObserver(&logger);
                }
            } else {
                std::cout << "Smth bad with loading, you can start new game!";
            }
        }

        GameControl gameControl; // считывание управления

        while (window.isOpen())
        {
           sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color::White);

            // ход врагов
            if(!player_step) {
                enemiesIteration(k_put, enemiesCreator.Get_Quantity());
                player_step = true;
            } else {  // ход игрока
                std::pair<int, int> control = gameControl.control();
                if (control.second == 0 && control.first == 0) { // save
                    saver.save(field, player, enemies, enemiesCreator.Get_Quantity(),
                               armor, heal, weapon, keys, k_put, player_step);
                    player_step = not player_step;
                } else if (control.second == -1 && control.first == -1){ // loading
                    int number = enemiesCreator.Get_Quantity();
                    if(saver.tryLoad()) {
                        saver.load(field, player, enemies, number, armor, heal, weapon, keys, k_put, player_step);
                        enemiesCreator.Set_Quantity(number);
                        for (int i = 0; i < enemiesCreator.Get_Quantity(); i++) {
                            enemies[i]->getEntity()->setObserver(&logger);
                        }
                    }
                    player_step = not player_step;
                } else if(playerIteration(condToWin.ConditionToWin(*player.get_player()),  control)) {
                    window.close();
                }
                player_step = not player_step;
            }


            // удаляем объекты, которые были подняты
            dellTakenObjects();

            IteratorOfField it(field);
            for(it.First(); !it.IsDone(); it++){
                fieldDrawer.Draw_Object(window, (*it)->GetState(), it.ret_x(), it.ret_y());
                if ((*it)->Get_Object())
                    entitiesDrawer.Draw_Object(window, typeid(*((*it)->Get_Object())).name(),
                                               (*it)->Get_Object()->get_position().first,
                                               (*it)->Get_Object()->get_position().second);
            }
            sf::sleep(sf::seconds(0.1));
            window.display();


        }


        delete[] k_put;
        dellEnemies(enemiesCreator.Get_Quantity());

    }

private:
    bool playerIteration(const bool CondToWin, std::pair<int, int> control){
        if (player.PlayerExist()) {
            if (player.act(field, control, CondToWin)) {
                player.dellPlayer(field);
                std::cout << "You win!!!!!!!\n";
                return true;
            }
        } else if (player.alive()) {
            player.dellPlayer(field);
            std::cout << "You lose\n";
            return true;
        }
        return false;
    }

    void enemiesIteration(bool* put, const int quantity){
        for (int i = 0; i < quantity; i++) {
            if (enemies[i]->entity_exist()) {
                enemies[i]->act(field, player.get_player());
            }
            if (enemies[i]->alive() && !enemies[i]->entity_exist()) {
                // если убили врага, то на поле генерируется ключ
                if (i == 0 && !put[i%3]) {
                    put[i%3] = true;
                    keys[0].put(field);
                }else if (i % 3 == 1 && !put[i%3]) {
                    put[i%3] = true;
                    keys[1].put(field);
                } else if (i % 3 == 2 && !put[i%3]) {
                    put[i%3] = true;
                    keys[2].put(field);
                }
                enemies[i]->removeEntityFromCell(field);
            }
        }
    }

    void dellTakenObjects(){
        for (auto & key : keys)
            if(key.is_put() && !key.entity_exist()) {
                key.take(field);
            }
        if(heal.is_put() && !heal.entity_exist()){
            heal.take(field);
        }
        if(armor.is_put() && !armor.entity_exist()){
            armor.take(field);
        }
        if(weapon.is_put() && !weapon.entity_exist()) {
            weapon.take(field);
        }
    }

    void dellEnemies(const int quantity){
        for (int i = 0; i < quantity; i++){
            if(dynamic_cast<GhostLogic*>(enemies[i]->getEntity()))
                delete dynamic_cast<GhostLogic*>(enemies[i]->getEntity());
            else if (dynamic_cast<Enemy2Logic*>(enemies[i]->getEntity()))
                delete dynamic_cast<Enemy2Logic*>(enemies[i]->getEntity());
            else if (dynamic_cast<Enemy3Logic*>(enemies[i]->getEntity()))
                delete dynamic_cast<Enemy3Logic*>(enemies[i]->getEntity());
        }
    }
};


#endif //GAME_GAME_H
