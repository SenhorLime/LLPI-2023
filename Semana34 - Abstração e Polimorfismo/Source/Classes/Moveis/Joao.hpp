#ifndef JOAO_HPP
#define JOAO_HPP

#include "Movel.hpp"

class Joao : public Movel {
public:
    Joao(int x, int y, int direcaoX, int direcaoY, std::string textura, sf::RenderWindow *screen);

    virtual ~Joao();

    void move(sf::Time dt);
};


#endif //JOAO_HPP
