#include <iostream>

class TipoInfo {
public:
  int x;
};

class TipoNodo {
public:
  TipoInfo Info;
  TipoNodo *Proximo;
};

class Fila {
public:
  TipoNodo *Primeiro;
  TipoNodo *Ultimo;

public:
  Fila() {
    Primeiro = NULL;
    Ultimo = NULL;
  }

  void InserirFilaEnc(int valor) {
    TipoNodo *NovoNodo;

    NovoNodo->Info.x = valor;
    NovoNodo->Proximo = NULL;

    if (Primeiro == NULL) {
      Primeiro = NovoNodo;
    } else {
      Ultimo->Proximo = NovoNodo;
    }

    Ultimo = NovoNodo;
  }

  bool Sucesso() {
    TipoNodo *Auxiliar;

    
    if (Primeiro != NULL) {
      Auxiliar = Primeiro;
      Primeiro = Auxiliar->Proximo;

      if (Primeiro == NULL) {
        Ultimo = NULL;

        return true;
      }
    }
    return false;
  }

  bool ConsultarFila() {
    if (Primeiro != NULL) {
        
    }
  }
};

int main() {}