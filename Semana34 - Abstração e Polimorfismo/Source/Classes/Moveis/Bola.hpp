#ifndef BOLA_HPP
#define BOLA_HPP

#include "Movel.hpp"

class Bola : public Movel {
protected:
    sf::CircleShape circle;
public:
    Bola(int x, int y, int direcaoX, int direcaoY, string textura, sf::RenderWindow *screen);

    virtual ~Bola();

    void move(sf::Time dt);

    void mostra();

    bool colide(sf::Sprite outraBola);

    sf::Sprite getSprite();
};


#endif //BOLA_HPP
