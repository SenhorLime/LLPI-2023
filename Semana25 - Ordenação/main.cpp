/*
 * main.cpp
 *
 *  Created on: Aug 24, 2023
 *      Author: Joao Vitor Lima
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Aluno {
public:
	unsigned int matricula;
	string nome;
	string grupo;

public:
	Aluno() {}

	Aluno(string linha) {
		string campo;

		stringstream ss(linha);

		std::getline(ss, campo, ';');
		this->matricula = std::atoi(campo.c_str());

		std::getline(ss, campo, ';');
		this->nome = campo;

		std::getline(ss, campo, ';');
		this->grupo = campo;

	}

	string toString() {
		stringstream ss;
		ss << "[ Matricula: " << matricula;
		ss << " | Nome: " << nome;
		ss << " | Grupo: " << grupo << " ]";

		return ss.str();
	}
};

vector<Aluno> carregaAlunos(std::string caminho) {
	// Array avancado para guardas alunos
	vector<Aluno> alunos;

	std::string linha; // Guarda a linha do arquivo

	ifstream arquivo(caminho.c_str());

	if (!arquivo.is_open()) {
		std::cerr << "Deu ruim na hora de abrir o arquivo";
		return alunos;
	}

	std::getline(arquivo, linha); // Pega e descarta a linha de titulo das colunas

	while (std::getline(arquivo, linha)) {
		Aluno Aluno(linha);
		alunos.push_back(Aluno);
	}

	return alunos;
}

void imprimeVetor(vector<Aluno> &alunos) {
	for (unsigned int i = 0; i < alunos.size(); i++) {
		cout << alunos[i].toString() << endl;
	}
}

void Bolha(std::vector<Aluno> &alunos) {
	Aluno aux;

	for (unsigned int i = 0; i < alunos.size() - 1; i++) {
		for (unsigned int j = 1; j < alunos.size() - i; j++) {
			if (alunos[i].matricula < alunos[j - 1].matricula) {
				aux = alunos[j];
				alunos[j] = alunos[j - 1];
				alunos[j - 1] = aux;
			}
		}
	}
}

int main() {
	std::string caminho = "lista3.txt";

	vector<Aluno> alunos = carregaAlunos(caminho);

	Bolha(alunos);
	imprimeVetor(alunos);

	return 0;
}

