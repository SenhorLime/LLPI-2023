//============================================================================
// Name        : Prova.cpp
// Author      : João Vitor Lima - T2
// Version     : 0.1 (Lab)
// Copyright   : Your copyright notice
// Description : Prova Pratica
//============================================================================

#include "Class.hpp"
#include "Functions.hpp"

int main (){
	std::string caminho = "barcos.csv";

	vector<Barco> Barcos = carregaBarcos(caminho);

	std::cout << "Primeiros Barcos: " << endl;
	imprimeBarcos(Barcos);

	for (int i = 0;  Barcos.size(); i++){
		for (int j = 0; j < i; j++){
			Barcos[i].atingido();
		}
	}

	return 0;
}
