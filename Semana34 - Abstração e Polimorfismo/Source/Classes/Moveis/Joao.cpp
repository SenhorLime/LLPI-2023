#include "Joao.hpp"

Joao::~Joao() {
    Movel::~Movel();
}

Joao::Joao(int x, int y, int direcaoX, int direcaoY, std::string textura, sf::RenderWindow *screen) :
        Movel(x, y, direcaoX, direcaoY, textura, screen) {
    sprite.setScale(0.1f, 0.1f);
}

void Joao::move(sf::Time dt) {
    testaColisaoComParede();

    this->sprite.move(velocidadeX * (dt.asSeconds() / 3), velocidadeY * dt.asSeconds());
}