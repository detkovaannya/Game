#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "game.h"
#include "Director.h"

void Game::GameStart() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Game");
    Field f;
    BaseFieldBuilder builder;
    Director dir;
    dir.CreateField(builder, f);
    while (window.isOpen())
    {
        // Обрабатываем события в цикле
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == sf::Event::Closed)
                // тогда закрываем его
                window.close();
        }
        // Установка цвета фона - белый
        window.clear(sf::Color::White);


        IteratorOfField it(f);
        for(it.First(); !it.IsDone(); it++){
            window.draw((*it)->GetIMG());
        }

        window.display();
    }
}