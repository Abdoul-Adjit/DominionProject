#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    window.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width)/2-250,(sf::VideoMode::getDesktopMode().height)/2-250));
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) window.close();
            if(event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                std::cout << " click" << std::endl;
                if(shape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
                {
                    std::cout << " click on" << std::endl;
                    window.clear();
                }
            }        
            
        }
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}