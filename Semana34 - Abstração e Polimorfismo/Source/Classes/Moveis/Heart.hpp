#ifndef HEART_HPP
#define HEART_HPP

#include "Movel.hpp"

class Heart : public Movel {
public:
    Heart(int x, int y, int direcaoX, int direcaoY, std::string textura, sf::RenderWindow *screen);

    virtual ~Heart();

    void move(sf::Time dt);

private:
    enum Status {
        MoveVertical,
        MoveHorizontal,
        MoveDiagonal
    };

    int colideCounter = 0;
    Status status;
private:
    void moveDiagonal(sf::Time dt);

    void moveVertical(sf::Time dt);

    void moveHorizontal(sf::Time dt);

};


#endif
