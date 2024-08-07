#include "Headers/InimigoProj.hpp"
#include <cmath>

using namespace sf;
using namespace std;


InimigoProje::InimigoProje(float radius, float speed, float startX, float startY, float targetX, float targetY)
    : speed(speed) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(startX, startY);

    float dx = targetX - startX;
    float dy = targetY - startY;
    float length = sqrt(dx * dx + dy * dy);
    direction = Vector2f(dx / length, dy / length);
}

void InimigoProje::move() {
    shape.move(direction * speed);
}

void InimigoProje::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
