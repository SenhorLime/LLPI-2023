#ifndef CARRINHOS_HPP
#define CARRINHOS_HPP

#include <iostream>
#include <string>
#include <sstream>

class Carros {
public:
	int carro_ID;
	std::string montadora;
	int cilindradas;
	std::string imagem;

	Carros() : carro_ID(0), montadora(""), cilindradas(0), imagem("") {}

	Carros(std::string line) {
		std::string dado;
		std::stringstream dataConvert(line);

		getline(dataConvert, dado, ',');
		carro_ID = std::stoi(dado);

		getline(dataConvert, dado, ',');
		montadora = (dado);

		getline(dataConvert, dado, ',');
		cilindradas = std::stoi(dado);

		getline(dataConvert, dado, ',');
		imagem = (dado);
	}

	std::string toString() {
		std::stringstream dataString;

		dataString << carro_ID << ", " << montadora << ", " << cilindradas << ", " << imagem;
		return dataString.str();
	}

	bool operator>(const Carros &outroCarro) {
		return montadora > outroCarro.montadora;
	}

	bool operator<(const Carros &outroCarro) {
		return montadora < outroCarro.montadora;
	}

	bool operator==(const Carros &outroCarro) {
		return montadora == outroCarro.montadora;
	}
};
#endif
