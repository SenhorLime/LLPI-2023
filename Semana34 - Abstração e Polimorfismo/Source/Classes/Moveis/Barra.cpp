#include "Barra.hpp"

Barra::~Barra() {
    Movel::~Movel();
}

Barra::Barra(int x, int y, int direcaoX, int direcaoY, std::string textura, sf::RenderWindow *screen) :
        Movel(x, y, direcaoX, direcaoY, textura, screen) {
}

void Barra::move(sf::Time dt) {
    testaColisaoComParede();
    this->sprite.move(velocidadeX * dt.asSeconds(), 0);
}