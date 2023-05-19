//============================================================================
// Name        : Semana13.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iomanip>
using std::fixed;
using std::setprecision;

#include "class.hpp"

vector<Aluno> carregaAlunos(std::string caminho) {
	// Array avancado para guardas alunos
	vector<Aluno> alunos;

	std::string linha; // Guarda a linha do arquivo

	ifstream arquivo(caminho.c_str());

	if(!arquivo.is_open()){
		std::cerr << "Deu ruim na hora de abrir o arquivo";
		return alunos;
	}

	std::getline(arquivo, linha); // Pega e descarta a linha de titulo das colunas

	while (std::getline(arquivo, linha)){
		Aluno Aluno(linha);
		alunos.push_back(Aluno);
	}

	return alunos;
}

void imprimeVetor(vector <Aluno> alunos){
	for (int i = 0; i < alunos.size(); i++){
		cout << alunos[i].toString() << endl;
	}
}

float imprimeMedia (vector <Aluno> alunos){
  float mediaTurma;

	for (int i = 0; i < alunos.size(); i++){
		mediaTurma = mediaTurma + alunos[i].pegaNota();
	}

  return (mediaTurma / alunos.size());
}

int main (){
	std::string caminho = "alunos.csv";

	vector<Aluno> alunos = carregaAlunos(caminho);

	Aluno novoAluno(23, "Osvaldo", 100, 50.4);
	alunos.push_back(novoAluno);

	imprimeVetor(alunos);
  
  cout << fixed << setprecision(2);
	cout << "\nA media da turma e: " << imprimeMedia(alunos);

	return 0;
}
