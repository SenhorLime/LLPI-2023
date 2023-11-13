#ifndef GAME_HPP
#define GAME_HPP

#include "Moveis/Movel.hpp"
#include "Moveis/Bola.hpp"
#include "Moveis/Barra.hpp"
#include "Moveis/Joao.hpp"
#include "Moveis/Heart.hpp"

/**
 * Enumera��o utilizada como constantes para determinar os tipos de objetos que podem ser gerados
 * Basicamente uma lista com Movel e cada um de seus filhos.
 * Aleat�rio � para gara��o 'aleat�ria', mas tambem marca o final do enum
 * e serve para determinar quantos elementos h� no enum.
 *
 */
enum OBJETO {
    MOVEL, BARRA, BOLA, NAVE, CORACAO, ALEATORIO //ALEATORIO � sempre o �ltimo e reprensenta o tamanho da enum
};

class Game {
private:
    sf::RenderWindow *window;
    vector<Movel *> moveis;
    sf::Clock globalClock;
    sf::Texture textureFundo;
    sf::Sprite fundoImage;
    sf::Font font;
    sf::Text txt;
    sf::Image image; // Icone!

public:
    Game();

private:
    void criaMovel(int x, int y, OBJETO objeto);

    void colide();
};


#endif //GAME_HPP
