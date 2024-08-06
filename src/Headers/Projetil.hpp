#ifndef PROJETIL_HPP
#define PROJETIL_HPP

#include <SFML/Graphics.hpp>

class Projetil {
public:
    Projetil(float radius, float speed, float startX, float startY, float targetX, float targetY);
    void move();
    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape shape;
    float speed;
    sf::Vector2f direction;
};

#endif // PROJETIL_HPP
