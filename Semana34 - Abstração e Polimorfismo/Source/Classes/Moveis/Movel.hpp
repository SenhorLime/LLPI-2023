#ifndef MOVEL_HPP
#define MOVEL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>

using namespace std;

class Movel {
protected:
    int velocidadeX = 100;
    int velocidadeY = 100;
    sf::Texture *texture;
    sf::RenderWindow *window;
    sf::Sprite sprite;

protected:
    bool testaColisaoComParede();

public:
    Movel(int x, int y, int direcaoX, int direcaoY, string textura, sf::RenderWindow *screen);

    virtual ~Movel();

    virtual void move(sf::Time dt);

    string toString();

    virtual void mostra();

    virtual sf::FloatRect getMyBounds();
};


#endif //MOVEL_HPP
