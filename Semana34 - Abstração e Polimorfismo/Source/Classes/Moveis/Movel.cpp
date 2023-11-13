#include "Movel.hpp"

Movel::Movel(int x, int y, int direcaoX, int direcaoY, std::string textura, sf::RenderWindow *screen) {
    this->window = screen;

    int vel = rand() % 500 + 100; // de 100 ~499.
    velocidadeX = vel * direcaoX;
    vel = rand() % 500 + 100; // de 100 ~499.
    velocidadeY = vel * direcaoY;

    texture = new sf::Texture();

    if (!texture->loadFromFile(textura)) {
        cout << "Erro ao carregar a imagem " << endl;
    }
    sprite.setTexture(*texture);

    //sf::Vector2f tamanho(90, 39);
    //sprite.setScale(tamanho.x / sprite.getLocalBounds().width,
    //		tamanho.y / sprite.getLocalBounds().height);

    sprite.setPosition(x, y);
    //cout << "Movel criado" << endl;
}

Movel::~Movel() {
    delete (texture);
}

void Movel::move(sf::Time dt) {
    testaColisaoComParede();
    this->sprite.move(velocidadeX * dt.asSeconds(), velocidadeY * dt.asSeconds());
}

string Movel::toString() {
    stringstream ss;

    sf::FloatRect retangulo = sprite.getGlobalBounds();
    ss << "X,Y[" << retangulo.left << "," << retangulo.top << "],"
       << " Vx,Vy[" << velocidadeX << "," << velocidadeY << "],"
       << "W,H[" << retangulo.width << "," << retangulo.height << "]";

    return ss.str();
}

void Movel::mostra() {
    window->draw(sprite);
    //cout << toString() << endl;
}

bool Movel::testaColisaoComParede() {
    int w = window->getSize().x;
    int h = window->getSize().y;
    sf::Vector2f posicao = sprite.getPosition();

    if (posicao.x + getMyBounds().width > w) {
        velocidadeX = -velocidadeX;
        posicao.x = w - getMyBounds().width;
        return true;
    } else if (posicao.x < 0) {
        velocidadeX = -velocidadeX;
        posicao.x = 0;
        return true;
    }

    if (posicao.y + getMyBounds().height > h) {
        velocidadeY = -velocidadeY;
        posicao.y = h - getMyBounds().height;
        return true;
    } else if (posicao.y < 0) {
        velocidadeY = -velocidadeY;
        posicao.y = 0;
        return true;
    }

    return false;
}

sf::FloatRect Movel::getMyBounds() {
    return sprite.getGlobalBounds();
}
