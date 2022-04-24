#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <string>
#include <iostream>;

int main()
{
    sf::Uint32 stile = sf::Style::Default;
    sf::RenderWindow window(sf::VideoMode(500,500), "SFML works!", stile);
    sf::CircleShape shape(25.f);
    sf::String buffer;
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
            case sf::Event::EventType::TextEntered:
                if (event.text.unicode == 8) {
                    buffer.erase(buffer.getSize() - 1);
                    window.setTitle(buffer);
                }
                else {
                    buffer += event.text.unicode;
                    window.setTitle(buffer);
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
