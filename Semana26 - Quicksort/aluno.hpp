//============================================================================
// Name        : Classe de dado Aluno
// Author      : Alisson RS
// Description : Atividade de avaliação de métodos de ordenação.
//============================================================================

#ifndef ALUNO_HPP_
#define ALUNO_HPP_

#include <iostream>
#include <string>
#include <sstream>

using std::stringstream;
using namespace std;

class Aluno {
public:
	string nome;
	int idade;
	string acao;

	//Construtor vazio - Só inicializa valores padrões.
	Aluno() :
			nome(""), idade(0), acao("") {
	}

	//Construtor com string - Quebra, converte e
	//insere dados nas variáveis.
	Aluno(string line) {
		string dado;
		stringstream ss(line); 	//stringstream => 	<sstream>

		getline(ss, dado, ',');
		nome = (dado);

		getline(ss, dado, ',');
		idade = atoi(dado.c_str());

		getline(ss, dado, ',');
		acao = (dado);
	}

	//A função toString volta o dado para o formato da linha no arquivo.
	string toString() {
		stringstream ss;
		ss << nome << "," << idade << "," << acao;
		return ss.str();
	}

	//Sobrecarga dos operadores de comparação.
	//Alunos são sempre comparados pela idade.
	bool operator>(const Aluno &outroAluno) {
		return idade > outroAluno.idade;
	}
	bool operator<(const Aluno &outroAluno) {
		return idade < outroAluno.idade;
	}
	bool operator==(const Aluno &outroAluno) {
		return idade == outroAluno.idade;
	}
	//Mais em https://pt.wikibooks.org/wiki/Programar_em_C%2B%2B/Sobrecarga_de_operadores

};

#endif /* ALUNO_HPP_ */
