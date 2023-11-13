#include "Bola.hpp"

Bola::~Bola() {
    Movel::~Movel();
}

Bola::Bola(int x, int y, int direcaoX, int direcaoY, std::string textura, sf::RenderWindow *screen) :
        Movel(x, y, direcaoX, direcaoY, textura, screen) {

    //Define origem no meio da bola.
    sf::FloatRect rect = sprite.getLocalBounds();
    sprite.setOrigin(rect.width / 2, rect.height / 2);

    //Centraliza imagem e aureola.
    const sf::Vector2f *posicao = &sprite.getPosition();
    circle.setRadius(5 + sprite.getLocalBounds().width / 2);
    circle.setOrigin(circle.getLocalBounds().width / 2,
                     circle.getLocalBounds().height / 2);
    circle.setPosition(sprite.getPosition());

    //Cor da aureola conforme posi��o e velocidade.
    sf::Uint8 r = int(posicao->x) % 255; //sf::Uint8 == short int.
    sf::Uint8 g = int(posicao->y) % 255;
    sf::Uint8 b = velocidadeY % 255;
    circle.setFillColor(sf::Color{r, g, b});
}

void Bola::move(sf::Time dt) {
    testaColisaoComParede();
    this->sprite.move(0, velocidadeY * dt.asSeconds());
    circle.setPosition(sprite.getPosition()); // Move aureola junto.
}

void Bola::mostra() {
    //Pinta circulo e aureola.
    window->draw(circle);
    window->draw(sprite);
}

sf::Sprite Bola::getSprite() {
    return sprite;
}
