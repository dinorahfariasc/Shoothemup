#include "Headers/Atirador.hpp"

Atirador::Atirador(float width, float height, float speed, int vida, float X, float Y)
    : w(width),
      h(height),
      spd(speed),
      life(vida),
      posX(X),
      posY(Y),
      shape(sf::Vector2f(width, height)),
      moving(false) {
    shape.setFillColor(sf::Color::Cyan);
    shape.setPosition(X, Y);
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
        
        shape.setPosition(posX, posY);
    }
}

void Atirador::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2f Atirador::getPosition() const {
    return shape.getPosition();
}