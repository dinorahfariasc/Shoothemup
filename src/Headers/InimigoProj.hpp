#ifndef INIMIGOPROJ_HPP
#define INIMIGOPROJ_HPP

#include <SFML/Graphics.hpp>

class InimigoProj {
public:
    InimigoProj(float radius, float speed, float startX, float startY, float targetX, float targetY);
    void move();
    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape shape;
    float speed;
    sf::Vector2f direction;
};

#endif // INIMIGOPROJ_HPP
