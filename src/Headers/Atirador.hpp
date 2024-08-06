#ifndef ATIRADOR_HPP
#define ATIRADOR_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class Atirador {
private:
    float w; // Largura
    float h; // Altura
    float spd; // Velocidade
    int life; // Vida
    sf::RectangleShape shape;
    sf::Vector2f direction;
    bool moving;

public:
    float posX; // Posição do personagem
    float posY; // Posição do personagem
    sf::Vector2f targetPosition;

    Atirador(float width, float height, float speed, int vida, float X, float Y);

    void moveTo(float x, float y);
    void updateMovement();
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
};

#endif // ATIRADOR_HPP
