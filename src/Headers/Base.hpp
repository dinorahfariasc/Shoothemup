#ifndef BASE_HPP
#define BASE_HPP

#include <SFML/Graphics.hpp>

class Base
{
private:
    int maxLife;
    int currentLife;
    sf::CircleShape shape;
    sf::Vector2f currentPosition;

public:
    Base(int life, float radius, float posX, float posY) :
    maxLife(life), currentLife(life), currentPosition(posX, posY)
    {
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(currentPosition.x - radius, currentPosition.y - radius);
    }

    void draw(sf::RenderWindow& window) { window.draw(shape); }

};

#endif