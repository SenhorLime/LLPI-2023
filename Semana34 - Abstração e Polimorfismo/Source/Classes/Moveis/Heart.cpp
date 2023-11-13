#include "Heart.hpp"

Heart::~Heart() {
    Movel::~Movel();
}

Heart::Heart(int x, int y, int direcaoX, int direcaoY, std::string textura, sf::RenderWindow *screen) :
        Movel(x, y, direcaoX, direcaoY, textura, screen) {
}

void Heart::move(sf::Time dt) {
    if (testaColisaoComParede() == true) {
        colideCounter++;
    }

    if (colideCounter <= 10) {
        int movementType = rand() % 3;
        sprite.move(0, 0);

        switch (movementType) {
            case 0:
                moveVertical(dt);
                break;
            case 1:
                moveHorizontal(dt);
                break;
            case 2:
                moveDiagonal(dt);
                break;
        }
    } else  {
        colideCounter = 0;
    }

}

void Heart::moveVertical(sf::Time dt) {
    status = MoveVertical;
    this->sprite.move(0, velocidadeY * dt.asSeconds());
}

void Heart::moveHorizontal(sf::Time dt) {
    status = MoveHorizontal;
    this->sprite.move(velocidadeX * dt.asSeconds(), 0);
}

void Heart::moveDiagonal(sf::Time dt) {
    status = MoveDiagonal;
    this->sprite.move(velocidadeX * dt.asSeconds(), velocidadeY * dt.asSeconds());
}

