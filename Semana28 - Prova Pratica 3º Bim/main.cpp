//============================================================================
// Name        : LP1-3Bim.cpp
// Author      : Joao Vitor Lima Zeferino
// Version     :
// Copyright   : Your copyright notice
// Description : Prova 3Bim
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "Includes/AbreArquivo.hpp"
#include "Includes/Carrinhos.hpp"
#include "Includes/QuickSort.hpp"
#include "Includes/InsertSort.hpp"
#include "Includes/Arvore.hpp"

using namespace std;

void imprimeDados(vector<Carros> carros, int max = 0) {
	max = (max == 0 ? carros.size() : max);
	for (int i = 0; i < max; ++i) {
		cout << carros[i].toString() << endl;
	}
}

int main () {
	// Questao 01 - Finalizada
	std::vector<string> lista1 = GerenciadorDeArquivo::carregaAquivo("Dados//lista1.csv");
	std::vector<string> lista2 = GerenciadorDeArquivo::carregaAquivo("Dados//lista2.csv");

	std::vector<Carros> carrinhos;
	for (unsigned int i = 0; i < lista1.size(); i++) {
		Carros novo(lista1[i]);
		carrinhos.push_back(novo);
	}

	std::vector<Carros> carroes;
		for (unsigned int i = 0; i < lista2.size(); i++) {
			Carros novo(lista2[i]);
			carroes.push_back(novo);
		}

	// Questao 02 - Finalizada
	std::cout << "\nLista 1 Ordernado usando Insertion Sort\n";
	insertionSort(carrinhos);
	imprimeDados(carrinhos);


	// Questao 03 - Finalizada
	std::cout << "\nLista 2 Ordernado usando Quick Sort\n";
	quickSort(carroes);
	imprimeDados(carroes);

	// Questao 04 - Finalizada
	Arvore arvore;

	for (unsigned int i = 0; i < lista1.size(); i++) {
		arvore.insere(carrinhos[i]);
	}

	arvore.imprime();
}
