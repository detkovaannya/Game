#include "DrawField.h"

DrawField::DrawField() {
    TexturesArray[IMP].loadFromFile(PATH_TO_BOARD_IMG);
    TexturesArray[EMP].loadFromFile(PATH_TO_EMPTY_CELL);
    TexturesArray[START].loadFromFile(PATH_TO_START_CELL);
    TexturesArray[FIN].loadFromFile(PATH_TO_END_CELL);
}

void DrawField::Draw_Object(sf::RenderWindow& window, CELL_STATES type, int x, int y) {
    sprite = sf::Sprite(TexturesArray[type]);
    sprite.setPosition((float)(x * SIZE_OF_SPRITE), (float)(y * SIZE_OF_SPRITE));
    window.draw(sprite);
}
