#include "Headers/Inimigo.hpp"
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

Inimigo::Inimigo(float width, float height, float speed, int vida, float X, float Y, const std::string& textureFile)
    : w(width),
      h(height),
      spd(speed),
      life(vida),
      posX(X),
      posY(Y),
      moving(false) {
    
    if (!texture.loadFromFile(textureFile)) {
        cerr << "Erro ao carregar a textura: " << textureFile << endl;
    } else {
        sprite.setTexture(texture);
        sprite.setPosition(X, Y);
        sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2); // Ajusta a origem para o centro
    }
}

void Inimigo::moveTo(float x, float y) {
    targetPosition = Vector2f(x, y);
    float dx = x - posX;
    float dy = y - posY;
    float length = sqrt(dx * dx + dy * dy);
    direction = Vector2f(dx / length, dy / length);
    moving = true;
}

void Inimigo::updateMovement() {
    if (moving) {
        float dx = direction.x * spd;
        float dy = direction.y * spd;

        if (sqrt(pow(targetPosition.x - posX, 2) + pow(targetPosition.y - posY, 2)) <= spd) {
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

void Inimigo::draw(RenderWindow& window) {
    window.draw(sprite);
}

Vector2f Inimigo::getPosition() const {
    return sprite.getPosition();
}