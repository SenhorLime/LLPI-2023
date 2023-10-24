#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <vector>

int main() {
  std::cout << "Questao 01" << std::endl;
  std::list<std::string> listaNomes = {
      "Benjamin", "Todd",     "Kathy", "Jane",   "Karen",
      "Sarah",    "Patricia", "Jesse", "Ronald", "Russell"};

  for (auto nome : listaNomes) {
    std::cout << nome << " ";
  }

  std::cout << "\nQuestao 02" << std::endl;
  for (std::list<std::string>::iterator it = listaNomes.begin(); it != listaNomes.end(); it++) {
    std::cout << *it << " ";
  }

  std::cout << "\nQuestao 03" << std::endl;
  // Segundo o site do C++ a std::list tem uma perfomance melhor em inserir,
  // extrair e mover elementos em qualquer posicao A principal desvantagem da
  // std::list e que nao e possivel acessar dados em uma posicao espeficica de
  // maneira direta
  std::vector<std::string> vectorNomes;
  for (std::list<std::string>::iterator it = listaNomes.begin(); it != listaNomes.end(); it++) {
    vectorNomes.push_back(*it);
  }

  listaNomes.clear();
  std::cout << "Lista vazia: " << listaNomes.empty() << std::endl;
  std::cout << "Vector vazio: " << vectorNomes.empty() << std::endl;

  std::cout << "\nQuestao 04" << std::endl;
  // Segundo o site C++ a std::stack armazena dados somente de um tipo
  // especifico e tem funcoes para acessar os seus elementos. Ela sempre da
  // 'push' ou 'pop' do ultimo elemento, alem disso ela tem a 'top' que retorna
  // o valor que esta no topo da lista
  std::stack<std::string> pilhaNomes;
  for (auto nome : vectorNomes) {
    pilhaNomes.push(nome);
  }

  vectorNomes.clear();
  std::cout << "Vector vazio: " << vectorNomes.empty() << std::endl;
  std::cout << "Pilha vazia: " << pilhaNomes.empty() << std::endl;

  std::cout << "\nQuestao 05" << std::endl;
  std::map<int, std::string> mapaNome;

  mapaNome[1] = "Benjamin";
  mapaNome[2] = "Todd";
  mapaNome[3] = "Kathy";
  mapaNome[4] = "Jane";
  mapaNome[5] = "Karen";
  mapaNome[6] = "Sarah";
  mapaNome[7] = "Patricia";
  mapaNome[8] = "Jesse";
  mapaNome[9] = "Ronald";
  mapaNome[10] = "Russel";

  for (auto nome : mapaNome) {
    std::cout << "Matricula: " << nome.first << ", Nome: " << nome.second << std::endl;
  }
}