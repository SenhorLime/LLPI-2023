//============================================================================
// Name        : LP1-28-PesquisaLxB.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   classe.cpp
 * Author: contagem
 *
 * Created on 19 de Setembro de 2018, 11:22
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "aluno.hpp"
#include "gerenciadorDeArquivos.hpp"
#include "QuickSort.hpp"
#include <vector>

using namespace std;
/* desnecess�rio devido ao uso de templates
 typedef long TChave;

 typedef struct {
 TChave chave;
 // outros componentes
 } TItem;
 */

template<typename T> class Dicionario {
public:
	int n, max;
	T *vetor;

	/* inicializa um dicionário */
	Dicionario() :
			n(0), max(10), vetor(NULL) {
		vetor = new T[max];
	}

	/* encontra e retorna o índice da chave x no dicionário */
	int find_linear(T chave) {

		for (int i = n - 1; i >= 0; i--) {
			if (vetor[i] == chave) {
				return i;
			}
		}
		return -1; // retorna -1 caso a chave não seja encontrada
	}

	/* insere um registro no dicionário */
	void insere(T x) {
		if (n == max) {
			T *newV = new T[max * 2];
			for (int i = 0; i < max; i++) {
				newV[i] = vetor[i];
			}
			delete[] vetor;
			vetor = newV;
			max *= 2;
		}
		// n é o tamanho
		vetor[n++] = x;
	}

	void imprimir() {

		for (int i = 0; i < n; i++)
			cout <<i<<"-"<< vetor[i].toString() << ";" << endl;
		cout << endl;

	}

	/* encontra o índice da chave x no dicionário */
	int find_binary(T x) {
		return find_Binary(0, n - 1, x); // t->n é o   tamanho
	}

	~Dicionario() {
		cout << "Deletando dicionario" << endl;
		delete[] vetor;
	}

private:
	/* encontra o índice da chave x no dicionário entre esq e dir */
	int find_Binary(int esq, int dir, T x) {
		int meio = (esq + dir) / 2;
		if (vetor[meio] != x && esq >= dir)
			return -1;
		else if (x > vetor[meio]) {
			return find_Binary(meio + 1, dir, x);
		} else if (x < vetor[meio]) {
			return find_Binary(esq, meio - 1, x);
		} else {
			return meio;
		}
	}

};


int main1(int argc, char **argv) {
	Dicionario<Aluno> dic;
	vector<Aluno> sortedAlunos;
	vector<string> lines = GerenciadoDeArquivo::carregaAquivo(
			"data/Lista2.csv");

	for (unsigned int i = 0; i < lines.size(); i++) {
		Aluno novo(lines[i], ';');
		sortedAlunos.push_back(novo);
	}

	quickSort<Aluno>(sortedAlunos);

	for (unsigned int i = 0; i < lines.size(); i++) {
		dic.insere(sortedAlunos[i]);
	}

	dic.imprimir();

	Aluno alunoPesquisar;

	alunoPesquisar.nome = "Zul";

	int resultado = dic.find_binary(alunoPesquisar);
	cout << "Chave " << alunoPesquisar.nome << " encontrado na posicao " << resultado << endl;

	alunoPesquisar.nome = "Cleitu";
	resultado = dic.find_binary(alunoPesquisar);
	cout << "Chave " << alunoPesquisar.nome << " encontrado na posicao " << resultado << endl;

	return 0;
}

