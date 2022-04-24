#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>

int main()
{
    sf::Uint32 stile = sf::Style::Default;
    sf::RenderWindow window(sf::VideoMode(500,500), "SFML works!", stile);
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
                window.close();
                break;
            case sf::Event::EventType::KeyPressed:
                if (event.key.code == sf::Keyboard::Key::Escape) {
                    window.setTitle("WOW");
                    Sleep(5000);
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
