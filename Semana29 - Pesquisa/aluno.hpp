//============================================================================
// Name        : Classe de dado Aluno
// Author      : Alisson RS
// Description : Atividade de avalia��o de m�todos de ordena��o.
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
	int matricula;
	string nome, sobrenome;

	//Construtor vazio - S� inicializa valores padr�es.
	Aluno() :
		matricula(0),nome(""),sobrenome("") {
	}

	//Construtor com string - Quebra, converte e
	//insere dados nas vari�veis.
	Aluno(string line, char demiliter = ',') {
		string dado;
		stringstream ss(line); 	//stringstream => 	<sstream>

		getline(ss, dado, demiliter);
		matricula = atoi(dado.c_str());

		getline(ss, dado, demiliter);
		nome = (dado);

		getline(ss, dado, demiliter);
		sobrenome = (dado);
	}

	//A fun��o toString volta o dado para o formato da linha no arquivo.
	string toString() {
		stringstream ss;
		ss <<matricula<<","<< nome << "," << sobrenome ;
		return ss.str();
	}

	//Sobrecarga dos operadores de compara��o.
	//Alunos s�o sempre comparados pela idade.
	bool operator>(const Aluno &outroAluno) {
		return nome > outroAluno.nome;
	}
	bool operator<(const Aluno &outroAluno) {
		return nome < outroAluno.nome;
	}
	bool operator==(const Aluno &outroAluno) {
		return nome == outroAluno.nome;
	}
	bool operator!=(const Aluno &outroAluno) {
		return nome != outroAluno.nome;
	}
	//Mais em https://pt.wikibooks.org/wiki/Programar_em_C%2B%2B/Sobrecarga_de_operadores

};

#endif /* ALUNO_HPP_ */
