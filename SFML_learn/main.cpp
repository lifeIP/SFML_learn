#include <SFML/Graphics.hpp>
#include <windows.h>
#include <thread>
#include <iostream>
#include <vector>

int main()
{
    sf::Uint32 stile = sf::Style::Fullscreen;
    sf::RenderWindow window(sf::VideoMode(), "SFML works!", stile);
    sf::CircleShape shape(25.f);
    shape.setFillColor(sf::Color::Cyan);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::EventType::Closed:
                if (event.key.code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
                break;

            case sf::Event::EventType::KeyPressed:
                if (event.key.code == sf::Keyboard::Key::W) {
                    window.close();
                }
                break;
            default:
                break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
