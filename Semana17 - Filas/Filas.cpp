#include <iostream>
#include <vector>

void InicializarFilaArr(int& limiteInferior, int& inicioFila, int& finalFila) {
  inicioFila = finalFila = limiteInferior - 1;
}

bool InserirFilaArr(int minhaFila[], int limiteInf, int limiteSup, int& inicioFila, int& finalFila, int valor) {
  if ((finalFila != inicioFila -1) && (inicioFila != limiteInf) || (finalFila != limiteSup)) {
    if (inicioFila == limiteInf -1) {
      inicioFila = finalFila = limiteInf;
    } else if (finalFila == limiteSup) {
      finalFila = limiteInf;
    } else {
      finalFila = finalFila + 1;
    }

    minhaFila[finalFila] = valor;

    return true;
  } else {
    return false;
  }
}

bool RemoverFilaArr (int limiteInferior, int limiteSuperior, int& inicioFila, int& finalFila) {
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

bool ConsultarFilaArr (int minhaFila[], int limiteInferior, int inicioFila, int valor) {
  if (inicioFila != limiteInferior - 1) {
    valor = minhaFila[inicioFila];
    return true;
  } else {
    return false;
  }
}

int main() {
  int minhaFila [15];
  int limiteInferior = 0;
  int limiteSuperior = 14;
  int inicioFila, finalFila;

  InicializarFilaArr(limiteInferior, inicioFila, finalFila);

  bool sucesso = InserirFilaArr(minhaFila, limiteInferior, limiteSuperior, inicioFila, finalFila, 42);
  if (sucesso == true) {
    std::cout << "A insercao funcionou";
  } else {
    std::cout << "A insercao falhou";
  }

  sucesso = RemoverFilaArr(limiteInferior, limiteSuperior, inicioFila, finalFila);
  if (sucesso == true) {
    std::cout << "\nA remocao funcionou";
  } else {
    std::cout << "\nA remocao falhou";
  }
  
  sucesso = ConsultarFilaArr(minhaFila, limiteInferior, inicioFila, 3);
  if (sucesso == true) {
    std::cout << "\nA consulta funcionou";
  } else {
    std::cout << "\nA consulta falhou";
  }


  return 0;
}
