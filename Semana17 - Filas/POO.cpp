#include <iostream>
#include <vector>

class Fila {
private:
  int limiteInferior;
  int limiteSuperior;
  int inicioFila;
  int finalFila;

  std::vector<int> minhaFila;

public:
  Fila (int limiteInf, int limiteSup) {
    limiteInferior = limiteInf;
    limiteSuperior = limiteSup;
    inicioFila = finalFila = limiteInferior - 1;
    minhaFila.resize(limiteSup - limiteInf + 1);
  }

  bool Inserir(int valor) {
    if ((finalFila != inicioFila - 1) && (inicioFila != limiteInferior) || (finalFila != limiteSuperior)) {
      if (inicioFila == limiteInferior - 1) {
        inicioFila = finalFila = limiteInferior;
      } else if (finalFila == limiteSuperior) {
        finalFila = limiteInferior;
      } else {
        finalFila = finalFila + 1;
      }

      minhaFila[finalFila] = valor;

      return true;
    } else {
      return false;
    }
  }

  bool Remover() {
    if (inicioFila != limiteInferior - 1) {
      if (inicioFila == finalFila) {
        inicioFila = finalFila = limiteInferior - 1;
      } else if (inicioFila == limiteSuperior) {
        inicioFila = limiteInferior;
      } else {
        inicioFila = inicioFila + 1;
      }

      return true;
    } else {
      return false;
    }
  }

  bool Consultar(int valor) {
    if (inicioFila != limiteInferior - 1) {
      valor = minhaFila[inicioFila];

      return true;
    } else {
      return false;
    }
  }
};

int main() {
  int limiteInferior = 0;
  int limiteSuperior = 14;

  Fila filaPOO(limiteInferior, limiteSuperior);

  if (filaPOO.Inserir(42)) {
    std::cout << "A insercao funcionou" << std::endl;
  } else {
    std::cout << "A insercao falhou" << std::endl;
  }

  if (filaPOO.Remover()) {
    std::cout << "A remocao funcionou" << std::endl;
  } else {
    std::cout << "A remocao falhou" << std::endl;
  }

  if (filaPOO.Consultar(42)) {
    std::cout << "A consulta funcionou" << std::endl;
  } else {
    std::cout << "A consulta falhou" << std::endl;
  }

  return 0;
}
