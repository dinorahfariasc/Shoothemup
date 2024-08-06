#ifndef ATIRADOR_HPP
#define ATIRADOR_HPP

#include <SFML/Graphics.hpp>

class Atirador {
public:
    Atirador(float width, float height, float speed, int vida, float X, float Y, const std::string& textureFile);
    void moveTo(float x, float y);
    void updateMovement();
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;

private:
    float w; // Largura
    float h; // Altura
    float spd; // Velocidade
    int life; // Vida
    float posX; // Posição do personagem
    float posY; // Posição do personagem
    sf::Vector2f targetPosition;
    sf::Vector2f direction;
    bool moving;
    sf::Sprite sprite; // Sprite do personagem
    sf::Texture texture; // Textura do sprite
};

#endif // ATIRADOR_HPP
