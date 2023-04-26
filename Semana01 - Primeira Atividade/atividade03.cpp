// Joao Vitor Lima - 01.04.2023
// Programa em C++ usando POO (Programacao Orientada a Objetos)
// O programa cria uma classe que armazena o nome, idade e identidade de dois alunos

#include "iostream"
#include "cstdlib"
#include "string"

using namespace std;

class Aluno { // Criacao de Classe
  public: // Todos podem ter a acesso as informacoes
    string nome;
    int idade;

    void defineIdentidade(string valor) {
      if (valor.size() >= 5){
        identidade = valor;
      } else {
        cout << "A identidade deve ter ao menos 5 caracteres";
      }
    }

    string pegaIdentidade(){
      return identidade;
    }

  private: // Somente alguns podem ter acesso
    string identidade;

};

int main () {
  Aluno aluno1;
  Aluno aluno2;
  string aux = "";

  // Pegados os dados do aluno1
  cout << "Entre com o nome do aluno: ";
  cin >> aluno1.nome;

  cout << "Entre com a idade do aluno: ";
  cin >> aluno1.idade;

  cout << "Entre com a identidade do aluno (maior que cinco caracteres): ";
  cin >> aux;
  aluno1.defineIdentidade(aux);
  
  // Exibindo os dados do aluno1
  cout << "\nO aluno 1, de nome " << aluno1.nome << " tem idade " << aluno1.idade;
  cout << " Identidade " << aluno1.pegaIdentidade() << "\n\n";


  // Pegando os dados do aluno2
  cout << "Entre com o nome do aluno: ";
  cin >> aluno2.nome;

  cout << "Entre com a idade do aluno: ";
  cin >> aluno2.idade;

  cout << "Entre com a identidade do aluno (maior que cinco caracteres): ";
  cin >> aux;
  aluno2.defineIdentidade(aux);

  cout << "\nO aluno 2, de nome " << aluno2.nome << " tem idade " << aluno2.nome;
  cout << " Identidade " << aluno2.pegaIdentidade();
}
