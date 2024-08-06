#include "Headers/Projetil.hpp"
#include <cmath>

Projetil::Projetil(float radius, float speed, float startX, float startY, float targetX, float targetY)
    : speed(speed) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(startX, startY);

    float dx = targetX - startX;
    float dy = targetY - startY;
    float length = std::sqrt(dx * dx + dy * dy);
    direction = sf::Vector2f(dx / length, dy / length);
}

void Projetil::move() {
    shape.move(direction * speed);
}

void Projetil::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
