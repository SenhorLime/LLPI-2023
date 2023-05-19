#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::stringstream;

class Aluno {
	private:
		int id;
		string nome;
		int subTurma;
		float nota;

	public:
		Aluno (int id, string nome, int subTurma, float nota){
			this -> id = id;
			this -> nome = nome;
			this -> subTurma = subTurma;
			this -> nota = nota;
		}

		Aluno (string linha){
			string campo;

			stringstream ss(linha);

			std::getline(ss, campo, ',');
			this -> id = std::atoi(campo.c_str());

			std::getline(ss, campo, ',');
			this -> nome = campo;

			std::getline(ss, campo, ',');
			this -> subTurma = std::atoi(campo.c_str());

			std::getline(ss, campo, ',');
			this -> nota = std::atof(campo.c_str());
		}

		string toString(){
			stringstream ss;
			ss << "[ ID: " << id;
			ss << ", Nome: " << nome;
			ss << ", Subturma: " << subTurma;
			ss << ", Nota: " << nota << " ]";

			return ss.str();
		}

		float pegaNota (){
			return nota;
		}
};

