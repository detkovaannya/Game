#include "DrawEntities.h"

DrawEntities::DrawEntities() {
    types[0] = "6Player";
    types[1] = "5Ghost";
    types[2] = "6Enemy2";
    types[3] = "6Enemy3";
    types[4] = "3Key";
    types[5] = "5Armor";
    types[6] = "4Heal";
    types[7] = "6Weapon";
    textures[0].loadFromFile(PATH_TO_PLAYER);
    textures[1].loadFromFile(PATH_TO_GHOST);
    textures[2].loadFromFile(PATH_TO_ENEMY2);
    textures[3].loadFromFile(PATH_TO_ENEMY3);
    textures[4].loadFromFile(PATH_TO_KEY);
    textures[5].loadFromFile(PATH_TO_ARMOR);
    textures[6].loadFromFile(PATH_TO_HEAL);
    textures[7].loadFromFile(PATH_TO_WEAPON);
}

void DrawEntities::Draw_Object(sf::RenderWindow &window, const std::string& type, int x, int y) {
    int index = 0;
    for (int i = 0; i < 8; i++){
        if (type == types[i]){
            index = i;
            i = 8;
        }
    }
    sprite = sf::Sprite(textures[index]);
    sprite.setPosition((float)(x * SIZE_OF_SPRITE), (float)(y * SIZE_OF_SPRITE));
    window.draw(sprite);

}
//6Player 5Ghost 6Enemy2 6Enemy3 3Key 5Armor 4Heal 6Weapon