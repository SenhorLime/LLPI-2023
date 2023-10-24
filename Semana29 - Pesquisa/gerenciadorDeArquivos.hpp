//============================================================================
// Name        : LP1-Gerenciador de arquivos.
// Author      : Alisson RS
// Description : Presente para não ter mais medo de arquivos csv.
//			   : Todas as funções são estáticas, então podem ser usadas
//			   : direto sem precisar de objeto somente pelo nome da
//			   : classe como GerenciadoDeArquivo.carregaAquivo("c:\teste.txt");
//============================================================================

#ifndef GERENCIADODEARQUIVO_HPP_
#define GERENCIADODEARQUIVO_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::stringstream;
using namespace std;

class GerenciadoDeArquivo {

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
			std::cerr << "O arquivo não pôde ser aberto." << std::endl;
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
			std::cerr << "Não foi possível abrir o arquivo." << std::endl;
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
			std::cerr << "Não foi possível abrir o arquivo." << std::endl;
			return false;
		}

		for (string line : linhas) {
			arquivo << line << std::endl;
		}

		arquivo.close();
		return true;
	}

};

/**
 * Exemplo de uma classe de dado.
 *
 * Qualquer que seja o formato do seu arquivo csv
 * somente garanta que sua classe de dado (seja ela
 * Aluno, Conta, Musica, GameObjetct) tenha ao menos
 * um construtor que receba uma string. Assim vc pode
 * pegar o array de vector e passar cada linha para o
 * construtor e automaticamente ele quebra a linha
 * colocando cada dado na variável correta.
 *
 */

class _DadoExemplo {
public:
	int x;
	string nome;
	float valor;

	//Construtor vazio - Só inicializa valores padrões.
	_DadoExemplo() :
			x(0), nome(""), valor(0) {
	}

	//Construtor com string - Quebra, converte e
	//insere dados nas variáveis.
	_DadoExemplo(string line, char delimiter = ',') {
		string dado;
		stringstream ss(line); 	//stringstream => 	<sstream>

		getline(ss, dado, delimiter);
		nome = (dado);

		getline(ss, dado, delimiter);
		x = atoi(dado.c_str());	//atoi =>  			<cstdlib>

		getline(ss, dado, delimiter);
		valor = strtof(dado.c_str(), NULL); 	//atof => <cstdlib>
												//NULL => <cstdio>
	}

	//A função toString volta o dado para o formato da linha no arquivo.
	string toString() {
		stringstream ss;
		ss << nome << "," << x << "," << valor;
		return ss.str();
	}

};

#endif /* GERENCIADODEARQUIVO_HPP_ */
