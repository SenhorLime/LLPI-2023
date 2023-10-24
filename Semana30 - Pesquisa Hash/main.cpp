//============================================================================
// Name        : Topico29_HashTable.cpp
// Author      : João Vitor Lima - INFO 2
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Includes/Sort.hpp"

class Celula {
public:
	int chave;

	Celula() {}

	Celula(int nChave) {
		chave = nChave;
	}

	//Sobrecarga dos operadores de compara��o.
	//Alunos s�o sempre comparados pela idade.
	bool operator>(const Celula &outraCelula) {
		return chave > outraCelula.chave;
	}
	bool operator<(const Celula &outraCelula) {
		return chave < outraCelula.chave;
	}
	bool operator==(const Celula &outraCelula) {
		return chave == outraCelula.chave;
	}
};

class HashTable {
private:
	int M; // tamanho da tabela
	std::vector<std::vector<Celula>> tabela;

	int h(int chave) {
		return chave % M;
	}

	int PesquisaLista(std::vector<Celula> lista, int chave) {
		for (unsigned int i = 0; i < lista.size(); i++) {
			if (lista[i].chave == chave) {
				return chave;
			}
		}

		return -1;
	}

	int RetiraLista(std::vector<Celula> lista, int chave) {
		for (unsigned int i = 0; i < lista.size(); i++) {
			if (lista[i].chave == chave) {
				lista.erase(lista.begin() + i);
				return chave;
			}
		}

		return -1;
	}

	void ImprimeLista(std::vector<Celula> lista) {
		for (unsigned int i = 0; i < lista.size(); i++) {
			std::cout << lista.at(i).chave;

			if (i + 1 != lista.size()) {
				std::cout << " - ";
			}
		}

	}

	void OrdenaLista(std::vector<Celula> lista) {
		quicksort<Celula>(lista);
	}

public:
	HashTable(int m) {
		M = m;

		for (int i = 0; i < M; i++) {
			std::vector<Celula> lista;
			tabela.push_back(lista);
		}
	}

	int Pesquisa(int chave) {
		int i = this->h(chave);

		if (tabela[i].empty()) {
			return -1;
		} else {
			int item = PesquisaLista(tabela[i], chave);

			if (item == -1) {
				return -1;
			} else {
				return item;
			}
		}
	}

	void Insere(int chave) {
		if (Pesquisa(chave) == -1) {
			int i = h(chave);
			tabela[i].push_back(chave);
			OrdenaLista(tabela[i]);
		} else {
			std::cout << "Registro presente -> " << chave << std::endl;
		}
	}

	int Retira(int chave) {
		int i = h(chave);
		int item = RetiraLista(tabela[i], chave);

		if (item == -1) {
			std::cout << "Registro nao presente -> " << chave << std::endl;
			return -1;
		} else {
			return item;
		}
	}

	void Imprime() {
		std::cout << "Hash de modulo %" << M << std::endl;

		for (int i = 0; i < M; i++) {
			std::cout << "h = " << i << "[ ";
			ImprimeLista(tabela[i]);
			std::cout << " ]" << std::endl;
		}
	}
};

int main() {
	int M = 7;
	HashTable tabela(M);

	std::vector<int> randNum;
	for (int i = 0; i < 100 + std::rand() % 1000; i++) {
		randNum.push_back(std::rand() % 250);
	}

	for (int i = 0; i < 25; i++) {
		tabela.Insere(randNum.at(i));
	}

	tabela.Imprime();
}
