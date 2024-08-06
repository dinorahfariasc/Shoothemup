#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "Headers/Atirador.hpp"
#include "Headers/Projetil.hpp"

using namespace sf;
using namespace std;


int main() {
    RenderWindow window(VideoMode(800, 600), "Game Window");

    // Carregar a textura de background
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("Assets/background.png");

    // Definir o sprite do background
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(0.5, 0.5);

    Atirador personagem(30.f, 30.f, 0.1, 100, 100.f, 100.f,"Assests/Personagem/handgun.png"); 
    vector<Projetil> projeteis;

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
                        projeteis.push_back(Projetil(5.f, 0.08, characterPos.x + 25.f - 2.5f, characterPos.y, event.mouseButton.x, event.mouseButton.y)); // Velocidade do projétil ajustada para 2
                    }
                    break;
            }
        }

        personagem.updateMovement();

        for (auto& projetil : projeteis) {
            projetil.move();
        }

        window.clear();
        personagem.draw(window);
        for (auto& projetil : projeteis) {
            projetil.draw(window);
        }
        window.display();
    }
    return 0;
}
