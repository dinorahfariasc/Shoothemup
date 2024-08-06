#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "Atirador.hpp"

using namespace sf;
using namespace std;

class Projectile {
public:
    CircleShape shape;
    float speed;
    Vector2f direction;

    Projectile(float radius, float speed, float startX, float startY, float targetX, float targetY)
        : speed(speed) {
        shape.setRadius(radius);
        shape.setFillColor(Color::Red);
        shape.setPosition(startX, startY);

        float dx = targetX - startX;
        float dy = targetY - startY;
        float length = sqrt(dx * dx + dy * dy);
        direction = Vector2f(dx / length, dy / length);
    }

    void move() {
        shape.move(direction * speed);
    }

    void draw(RenderWindow& window) {
        window.draw(shape);
    }
};


int main() {
    RenderWindow window(VideoMode(800, 600), "Game Window");
    Atirador personagem(50.f, 50.f, 0.1, 100, 100.f, 100.f); // Velocidade do personagem ajustada para 2
    vector<Projectile> projectiles;

    while (window.isOpen()) {
        Event event; // Inicialização da variável que captura eventos
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed: // Case para a captura de evento de teclas pressionadas
                    if (event.key.code == Keyboard::Escape) {  // Fechar a aplicação em caso de apertar 'Esc'
                        window.close();
                    }
                    break;
                case Event::MouseButtonPressed:
                    if (event.mouseButton.button == Mouse::Right) {
                        personagem.moveTo(event.mouseButton.x, event.mouseButton.y);
                    }
                    if (event.mouseButton.button == Mouse::Left) {
                        Vector2f characterPos = personagem.getPosition();
                        projectiles.push_back(Projectile(5.f, 0.08, characterPos.x + 25.f - 2.5f, characterPos.y, event.mouseButton.x, event.mouseButton.y)); // Velocidade do projétil ajustada para 2
                    }
                    break;
            }
        }

        personagem.updateMovement();

        for (auto& projectile : projectiles) {
            projectile.move();
        }

        window.clear();
        personagem.draw(window);
        for (auto& projectile : projectiles) {
            projectile.draw(window);
        }
        window.display();
    }
    return 0;
}
