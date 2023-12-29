#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

using namespace std;

class Movel {
private:
	int posX, posY;

public:
	Movel () = default;

	Movel (int  x, int y) {
		posX = x;
		posY = y;
	}

	~Movel () { std::cout << "Destruida" << std::endl; }

public:
	static std::string mostrarNome(Movel *movel) { return typeid(*movel).name(); }

	virtual void mover() {}

	virtual std::string toString() {
		std::stringstream ss;

		ss << "PosX = " << posX << ", PosY = " << posY;

		return ss.str();
	}

	void setPosX(int x) { posX = x; }

	void setPosY(int y) { posY = y; }

	int getPosX() { return Movel::posX; }

	int getPosY() { return Movel::posY; }
};

class Carro : public Movel {
private:
	int portas = 0;

public:
	Carro() = default;

public:
	void setPosX(int posX) { Movel::setPosX(posX); }

	void setPosY(int posY) { Movel::setPosY(posY); }

	void mover() {
		Movel::setPosX(Movel::getPosX() + 10);
		Movel::setPosY(Movel::getPosY() + 10);
	}

	std::string toString() {
		std::stringstream ss;

		ss << "PosX = " << getPosX() << ", PosY = " << getPosY() << ", portas = " << portas;

		return ss.str();
	}
};

class Moto : public Movel {
private:
	int escapamentos = 0;

public:
	Moto() = default;

	void setPosX(int posX) { Movel::setPosX(posX); }

	void setPosY (int posY) { Movel::setPosY(posY); }

	void mover() {
		Movel::setPosX(Movel::getPosX() + 16);
		Movel::setPosY(Movel::getPosY() + 16);
	}

	std::string toString() {
		std::stringstream ss;

		ss << "PosX = " << getPosX() << ", PosY = " << getPosY() << ", escapamentos = " << escapamentos;

		return ss.str();
	}
};

class Bola : public Movel {
private:
	int raio;

public:
	Bola(int raio) {
		while (raio < 5 || raio > 10) {
			std::cout << "Os valores para o raio podem ser somente inteiros entre 5 e 10" << std::endl;
			std::cout << "Digite um novo valor valido: ";
			std::cin >> raio;
		}
		this-> raio = raio;

		Movel::setPosX(raio);
		Movel::setPosY(raio);
	}

public:
	void mover() {
		Movel::setPosX(Movel::getPosX() + 5);
		Movel::setPosY(Movel::getPosY() + 5);
	}

	std::string toString() {
		std::stringstream ss;

		ss << "PosX = " << getPosX() << ", PosY = " << getPosY() << ", raio = " << raio;

		return ss.str();
	}
};


int main() {
    cout << "Avaliação Bimestral" << endl;

    //Questão 1.
    //=========================================================
    Carro carro;
    Moto moto;
    Bola bola(4);

    carro.setPosX(10);
    carro.setPosY(10);

    moto.setPosX(19);
    moto.setPosY(moto.getPosX() + 5);



    //Questão 3.
    //=========================================================
    carro.mover();
    moto.mover();
    bola.mover();


    //Questão 2.
    //=========================================================
    cout << "========================" << endl;
    cout << "toString() das classes." << endl;
    cout << carro.toString() << endl;
    cout << moto.toString() << endl;
    cout << bola.toString() << endl;



    cout << "========================" << endl;
    cout << "Nome das classes." << endl;
    cout << Movel::mostrarNome(&carro) << endl;
    cout << Movel::mostrarNome(&moto) << endl;
    cout << Movel::mostrarNome(&bola) << endl;

    cout << "========================" << endl;
    cout << "FIM." << endl;
    return 0;
}


