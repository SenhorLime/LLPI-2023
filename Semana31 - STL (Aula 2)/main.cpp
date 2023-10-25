/*
 * main.cpp
 *
 *  Created on: 19 de out. de 2023
 *      Author: user
 */

#include "gerenciadorDeArquivos.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <list>
#include <vector>

class Funcionario {
private:
	int identificador;
	std::string nome;
	std::string pais;
	std::string email;

private:
	bool verificaEmail() {
		std::regex tags("^+@+^+.");

		if (std::regex_match(email, tags)) {
			return true;
		} else {
			return false;
		}
	}

public:
	Funcionario (int identificador, std::string nome, std::string pais, std::string email) {
		this->identificador = identificador;
		this->nome = nome;
		this->pais = pais;
		this->email = email;
	}

	Funcionario (std::string line) {
		std::string dado;
		std::stringstream dataConvert(line);

		getline(dataConvert, dado, ';');
		identificador = std::stoi(dado);

		getline(dataConvert, dado, ';');
		nome = (dado);

		getline(dataConvert, dado, ';');
		pais = (dado);

		getline(dataConvert, dado, ';');
		email = (email);
	}

	std::string toString() {
		std::stringstream data;
		data << identificador << ";" << nome << ";" << pais << ";" << email
				<< std::endl;

		return data.str();
	}

	Funcionario clone() {
		Funcionario clonado(identificador, nome, pais, email);

		return clonado;
	}

	bool operator>(const Funcionario &outroFuncionario) {
		return identificador > outroFuncionario.identificador;
	}

	bool operator<(const Funcionario &outroFuncionario) {
		return identificador < outroFuncionario.identificador;
	}

	bool operator==(const Funcionario &outroFuncionario) {
		return identificador == outroFuncionario.identificador;
	}

//	Questao 07
	friend ostream &operator<<(ostream& output, Funcionario& funcionario) {
		output << funcionario.toString();

		return output;
	}
};

void imprimeLista (std::list<Funcionario> listaFuncionario) {
	std::cout << "Imprimindo lista de Funcionarios" << std::endl;

	for (auto funcionario : listaFuncionario) {
		std::cout << funcionario << std::endl;
	}
}
int main() {
//	Questao 02
	Funcionario funcionario0(0, "Ariane Labadie", "Comoros", "Aaron@karolann.tv");
	Funcionario funcionario1(1, "Destany O'Kon", "Guam", "Isabella@caroline.biz");
	Funcionario funcionario2(2, "Roger Toy", "Grenada", "Antoinette@annette.tv");

//	Questao 03
	std::list<Funcionario> funcionarioLista;
	funcionarioLista.push_back(funcionario0);
	funcionarioLista.push_back(funcionario1);
	funcionarioLista.push_back(funcionario2);

	imprimeLista(funcionarioLista);

//	Questao 04
	funcionarioLista.clear();
	std::vector<std::string> lines = GerenciadoDeArquivo::carregaAquivo("dados.csv");

	for (unsigned int i = 0; i < 10; i++) {
		funcionarioLista.push_back(Funcionario(lines.at(i)));
	}

//	Questao 05
	for (unsigned int i = 10; i < lines.size(); i++) {
		funcionarioLista.push_back(Funcionario(lines.at(i)));
	}

//	Questao 06
	std::string saveOnFile;
	for (auto funcionario : funcionarioLista) {
        std::regex tags("Brazil");

        if (std::regex_search(funcionario.toString(), tags)) {
            saveOnFile += funcionario.toString() += "\n";
        }
	}

	GerenciadoDeArquivo::escreveLinhaNoAquivo("dados2.csv", saveOnFile, false);

}
