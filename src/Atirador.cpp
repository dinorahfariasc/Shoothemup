#include "Headers/Atirador.hpp"
#include <iostream>
#include <cmath>

Atirador::Atirador(float width, float height, float speed, int vida, float X, float Y, const std::string& textureFile)
    : w(width),
      h(height),
      spd(speed),
      life(vida),
      posX(X),
      posY(Y),
      moving(false) {
    
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Erro ao carregar a textura: " << textureFile << std::endl;
    } else {
        sprite.setTexture(texture);
        sprite.setPosition(X, Y);
        sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2); // Ajusta a origem para o centro
    }
}

void Atirador::moveTo(float x, float y) {
    targetPosition = sf::Vector2f(x, y);
    float dx = x - posX;
    float dy = y - posY;
    float length = std::sqrt(dx * dx + dy * dy);
    direction = sf::Vector2f(dx / length, dy / length);
    moving = true;
}

void Atirador::updateMovement() {
    if (moving) {
        float dx = direction.x * spd;
        float dy = direction.y * spd;

        if (std::sqrt(std::pow(targetPosition.x - posX, 2) + std::pow(targetPosition.y - posY, 2)) <= spd) {
            posX = targetPosition.x;
            posY = targetPosition.y;
            moving = false;
        } else {
            posX += dx;
            posY += dy;
        }
        
        sprite.setPosition(posX, posY);
    }
}

void Atirador::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::Vector2f Atirador::getPosition() const {
    return sprite.getPosition();
}
