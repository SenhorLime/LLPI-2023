#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::stringstream;

#include <vector>
using std::vector;

std::vector<Barco> carregaBarcos(std::string caminho){
	vector<Barco> Barcos;

	std::string line;

	ifstream arquivo(caminho.c_str());

	if(!arquivo.is_open()){
		std::cerr << "Deu ruim na hora de abrir o arquivo";

		return Barcos;
	}

	std::getline (arquivo, line);

	while (std::getline (arquivo, line)){
		Barco Barco(line);

		Barcos.push_back(Barco);
	}

	return Barcos;
}


void imprimeBarcos (vector<Barco> Barcos){
	for (int i = 0; i < Barcos.size(); i++){
		cout << Barcos[i].toString() << endl;
	}
}

/*void salvaBarcos (std::string caminho, vector<Barco> Barcos){
	std::ofstream outFile;

	outFile.open(caminho, std::ios::app);


}*/
