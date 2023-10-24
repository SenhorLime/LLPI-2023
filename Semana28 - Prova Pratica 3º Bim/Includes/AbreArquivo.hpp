#ifndef ABREARQUIVO_HPP
#define ABREARQUIVO_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::stringstream;
using namespace std;

class GerenciadorDeArquivo {

public:
	static vector<string> carregaAquivo(string caminho) {

		string line;
		vector<string> linhas;

		ifstream arquivo(caminho.c_str());

		if (arquivo.is_open()) {
			//Busca dados no arquivo.
			getline(arquivo, line); //descarta rotulo

			while (getline(arquivo, line)) {
				linhas.push_back(line);
			}

		} else {
			std::cerr << "O arquivo nao pode ser aberto." << std::endl;
		}
		return linhas;
	}

	static bool escreveLinhaNoAquivo(string caminho, string line,
			bool adicionar) {
		ofstream arquivo;

		if (adicionar == true) {
			arquivo.open(caminho, std::ios::app);
		} else if (adicionar == false) {
			arquivo.open(caminho);
		}

		if (!arquivo.is_open()) {
			std::cerr << "Nao foi possivel abrir o arquivo." << std::endl;
			return false;
		}

		arquivo << line << std::endl;

		arquivo.close();
		return true;
	}

	static bool escreveVetorNoAquivo(string caminho, vector<string> linhas,
			bool adicionar) {
		std::ofstream arquivo;

		if (adicionar == true) {
			arquivo.open(caminho, std::ios::app);
		} else if (adicionar == false) {
			arquivo.open(caminho);
		}

		if (!arquivo.is_open()) {
			std::cerr << "Nao foi possivel abrir o arquivo." << std::endl;
			return false;
		}

		for (string line : linhas) {
			arquivo << line << std::endl;
		}

		arquivo.close();
		return true;
	}

};
#endif
