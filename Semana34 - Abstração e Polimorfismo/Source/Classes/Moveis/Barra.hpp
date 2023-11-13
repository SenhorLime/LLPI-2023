#ifndef BARRA_HPP
#define BARRA_HPP

#include "Movel.hpp"

class Barra : public Movel {
public:
    Barra(int x, int y, int direcaoX, int direcaoY, std::string textura, sf::RenderWindow *screen);

    virtual ~Barra();

    void move(sf::Time dt);
};


#endif //BARRA_HPP
