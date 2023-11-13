#include "Game.hpp"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(1280, 768), "Poli Poli Morfismo!!");
    image.loadFromFile("assets/cogumelo.png");
    window->setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());


    window->setFramerateLimit(60);

    textureFundo.loadFromFile("assets/fundo.png");
    fundoImage.setTexture(textureFundo);


    font.loadFromFile("assets/x-files.ttf");
    txt.setFont(font);
    txt.setFillColor(sf::Color::Blue);
    txt.setCharacterSize(56);
    txt.setString("Clique na tela para criar!");
    sf::FloatRect bounds(txt.getLocalBounds());
    txt.setPosition(
            window->getSize().x / 2 - (bounds.left + bounds.width / 2),
            window->getSize().y / 2 - (bounds.top + bounds.height / 2));

    /**** LOOP DO JOGO ****/
    while (window->isOpen()) {
        //Controle de tempo de dura��o do loop.
        sf::Time duration = globalClock.restart();

        sf::Event event;
        // Loop de processamento de eventos
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    //Cria objeto no local do click.
                    criaMovel(event.mouseButton.x, event.mouseButton.y,
                              OBJETO::ALEATORIO);
                    txt.setFillColor(sf::Color::Transparent);
                }

            }
        }

        /**** Movimenta os objetos ****/
        for (unsigned int i = 0; i < moveis.size(); ++i) {
            moveis.at(i)->move(duration);
        }

        colide();
        /**** DESENHA A TELA E OS OBJETOS ****/

        window->clear(sf::Color::White);
        window->draw(fundoImage);
        window->draw(txt);
        for (unsigned int i = 0; i < moveis.size(); ++i) {
            moveis.at(i)->mostra();
        }

        window->display();
        //Aguarda x milissegundos
        //sf::sleep(sf::milliseconds(100));

    }
    /**** FIM DO LOOP PRINCIPAL DO JOGO ****/
}

void Game::criaMovel(int x, int y, OBJETO objeto) {
    int direcaoX, direcaoY;
    Movel *meuMovel = nullptr;
    string imagem;

    //Numero aleatorio 0 ou 1
    int aleatorio = rand() % 2;
    direcaoX = (aleatorio == 0 ? 1 : -1);
    aleatorio = rand() % 2;
    direcaoY = (aleatorio == 0 ? 1 : -1);

    if (objeto == OBJETO::ALEATORIO) {
        aleatorio = rand() % OBJETO::ALEATORIO;  //Aleat�rio � o tamanho do enum(� o ultimo).
        objeto = static_cast<OBJETO>(aleatorio);
    }

    //Seleciona o tipo de objeto a ser criado com base
    //na ordem do pr�ximo objeto
    switch (objeto) {
        case OBJETO::MOVEL:
            imagem = "assets/movel.png";
            meuMovel = new Movel(x, y, direcaoX, direcaoY, imagem, window);
            break;
        case OBJETO::BOLA:
            imagem = "assets/bola.png";
            meuMovel = new Bola(x, y, direcaoX, direcaoY, imagem, window);
            break;
        case OBJETO::BARRA:
            imagem = "assets/barra.png";
            meuMovel = new Barra(x, y, direcaoX, direcaoY, imagem, window);
            break;
        case OBJETO::NAVE:
            imagem = "assets/cogumelo.png";
            meuMovel = new Joao(x, y, direcaoX, direcaoY, imagem, window);
            break;
        case OBJETO::CORACAO:
            imagem = "assets/coracao.png";
            meuMovel = new Heart(x, y, direcaoX, direcaoY, imagem, window);
            break;
        default:
            imagem = "assets/bola.png";
            meuMovel = new Bola(x, y, direcaoX, direcaoY, imagem, window);
            break;
    }

    if (meuMovel != nullptr)
        moveis.push_back(meuMovel);
}

void Game::colide() {
    for (unsigned int i = 0; i < moveis.size(); i++) {
        for (unsigned int j = i + 1; j < moveis.size(); j++) {
            if (typeid(*moveis.at(i)) == typeid(Bola) && typeid(*moveis.at(j)) == typeid(Bola)) {
                if (moveis.at(i)->getMyBounds().intersects(moveis.at(j)->getMyBounds())) {
                    moveis.erase(moveis.begin() + i);
                    moveis.erase(moveis.begin() + j - 1);
                }
            }
        }
    }
}