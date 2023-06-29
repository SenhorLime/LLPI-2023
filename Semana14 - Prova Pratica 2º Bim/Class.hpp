#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::stringstream;


class Barco {
	private:
		int linha;
		int coluna;
		int tamanho;
		int partesAtingidas;
		string imagem;
		string direcao;

	public:
		Barco (){
			this -> linha = 0;
			this -> coluna = 0;
			this -> tamanho = 0;
			this -> partesAtingidas = 0;
			this -> imagem = "";
			this -> direcao = ' ';
		}

		Barco (int linha, int coluna, int tamanho, int partesAtingidas, string imagem, char direcao){
			this -> linha = linha;
			this -> coluna = coluna;
			this -> tamanho = tamanho;
			this -> partesAtingidas = partesAtingidas;
			this -> imagem = imagem;
			this -> direcao = direcao;
		}

		Barco (string line){
			std::string campo;

			stringstream ss(line);

			std::getline (ss, campo, ',');
			this -> linha = std::atoi(campo.c_str());

			std::getline (ss, campo, ',');
			this -> coluna = std::atoi(campo.c_str());

			std::getline (ss, campo, ',');
			this -> tamanho = std::atoi(campo.c_str());

			std::getline (ss, campo, ',');
			this -> partesAtingidas = std::atoi(campo.c_str());

			std::getline (ss, campo, ',');
			this -> imagem = campo;

			std::getline (ss, campo, ',');
			this -> direcao = campo;
		}

		void atingido (){
			this -> partesAtingidas = partesAtingidas + 1;
		}

		bool afundado(){
			if (partesAtingidas >= tamanho){
				return true;
			} else{
				return false;
			}
		}

		string toString(){
			stringstream ss;

			ss << "[ Linha: " << linha;
			ss << ", Coluna: " << coluna;
			ss << ",  Tamanho: " << tamanho;
			ss << ", Partes Atingidas: " << partesAtingidas;
			ss << ", Imagem: " << imagem;
			ss << ", Direcao: " << direcao << " ]";

			return ss.str();
		}
};
