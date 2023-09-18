#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Josephus Problem");
    window.setFramerateLimit(60);

   /* 
    sf::CircleShape cir;

    sf::Vector2f circlePosition(600, 350);
    cir.setPosition(circlePosition);*/
    
    sf::CircleShape cir;
    sf::Vector2f cirPosition(600, 350);
    cir.setPosition(cirPosition);
    cir.setFillColor(sf::Color::Cyan);
    cir.setRadius(10);

    sf::CircleShape dir;
    sf::Vector2f dirPosition(500, 250);
    dir.setPosition(dirPosition);
    dir.setFillColor(sf::Color::Yellow);
    dir.setRadius(10);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        window.clear();
       
        window.draw(cir);
        window.draw(dir);
    
        window.display();







    }



    return 0;
}