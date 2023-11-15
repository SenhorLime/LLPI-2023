#ifndef SEMANA32_QUESTOES_HPP
#define SEMANA32_QUESTOES_HPP

#include "Search.hpp"
#include "HashTable.hpp"
#include "FileManager.hpp"
#include "../Classes/Aluno.hpp"
#include "../Classes/Carro.hpp"

void questao1() {
  Dicionario<Carro> dicionario;
  std::vector<Carro> vectorCarro;
  std::vector<std::string> lines = FileManager::loadFile("lista0.csv");

  for (const auto &line: lines) {
    vectorCarro.emplace_back(line);
    dicionario.insert(vectorCarro.back());
  }

  Carro buscaCarro;
  std::cout << "Digite o codigo do carro que deseja encontrar: ";
  std::cin >> buscaCarro.codigo;

  int posicao = dicionario.findLinear(buscaCarro);
  std::cout << "O carro de codigo (" << buscaCarro.codigo << ") foi encontrado na posicao (" << posicao << "). ";
  std::cout << "Aqui estao as informacoes da busca: " << std::endl;
  std::cout << " Codigo | Montadora | Cilindradas | Imagem " << std::endl << vectorCarro.at(posicao);
};

void questao2() {
  std::vector<Aluno> vectorAluno;
  std::vector<std::string> lines = FileManager::loadFile("Lista2.csv");

  for (const auto &line: lines) { vectorAluno.emplace_back(line, ';'); }

  HashTable<Aluno> hashTable(6);

  for (const auto &aluno: vectorAluno) { hashTable.insert(aluno); }

  int buscaMatricula;
  std::cout << "Digite a matricula que deseja buscar: ";
  std::cin >> buscaMatricula;

  Aluno buscarAluno = hashTable.search(buscaMatricula);

  std::cout << "O aluno de matricula (" << buscarAluno.matricula << ") foi encontrado. ";
  std::cout << "Aqui estao as informacoes da busca: " << std::endl;
  std::cout << " Matricula | Nome | Sobrenome " << std::endl << buscarAluno;
}

void questao3() {
  Dicionario<Aluno> dicionario;
  std::vector<Aluno> vectorAluno;
  std::vector<std::string> lines = FileManager::loadFile("Lista2.csv");

  for (const auto &line: lines) {
    vectorAluno.emplace_back(line, ';');
    dicionario.insert(vectorAluno.back());
  }

  Aluno buscaAluno;
  std::cout << "Digite a matricula do aluno que deseja encontrar: ";
  std::cin >> buscaAluno.matricula;

  int posicao = dicionario.findLinear(buscaAluno);
  std::cout << "O aluno de matricula (" << buscaAluno.matricula << ") foi encontrado na posicao (" << posicao << "). ";
  std::cout << "Aqui estao as informacoes da busca: " << std::endl;
  std::cout << " Matricula | Nome | Sobrenome " << std::endl << vectorAluno.at(posicao);
};

void questao4() {
  std::vector<Carro> vectorCarro;
  std::vector<std::string> lines = FileManager::loadFile("lista0.csv");

  for (const auto &line: lines) { vectorCarro.emplace_back(line, ','); }

  HashTable<Carro> hashTable(6);

  for (const auto &carro: vectorCarro) { hashTable.insert(carro); }

  int buscaCodigo;
  std::cout << "Digite a matricula que deseja buscar: ";
  std::cin >> buscaCodigo;

  Carro buscarCarro = hashTable.search(buscaCodigo);

  std::cout << "O carro de codigo (" << buscarCarro.codigo << ") foi encontrado. ";
  std::cout << "Aqui estao as informacoes da busca: " << std::endl;
  std::cout << " Codigo | Montadora | Cilindradas | Imagem " << std::endl << buscarCarro;
};

#endif
