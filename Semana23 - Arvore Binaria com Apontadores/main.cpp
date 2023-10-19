#include <iostream>

class Arvore {
public:
  int info;

  Arvore *Esquerda;
  Arvore *Direita;

public:
  Arvore() {}

  Arvore *Buscar(Arvore *search, int valor) {
    if (search == NULL) {
      return NULL;
    } else if (search->info > valor) {
      return Buscar(search->Esquerda, valor);
    } else if (search->info < valor) {
      return Buscar(search->Direita, valor);
    } else {
      return search;
    }
  }

  Arvore *Inserir(Arvore *insert, int valor) {
    if (insert == NULL) {
      insert = new Arvore();

      insert->info = valor;
      insert->Esquerda = insert->Direita = NULL;
    } else if (valor < insert->info) {
      insert->Esquerda = insert->Inserir(insert->Esquerda, valor);
    } else {
      insert->Direita = insert->Inserir(insert->Direita, valor);
    }

    return insert;
  }

  Arvore *Remover(Arvore *remove, int valor) {
    if (remove == NULL) {
      return NULL;
    } else if (remove->info > valor) {
      remove->Esquerda = remove->Remover(remove->Esquerda, valor);
    } else if (remove->info < valor) {
      remove->Direita = Remover(remove->Direita, valor);
    } else {
      if (remove->Esquerda == NULL && remove->Direita == NULL) {
        free(remove);
        remove = NULL;
      } else if (remove->Esquerda == NULL) {
        Arvore *tree = remove;

        remove = remove->Direita;
        free(tree);
      } else if (remove->Direita == NULL) {
        Arvore *tree = remove;

        remove = remove->Esquerda;
        free(tree);
      } else {
        Arvore *f = remove->Esquerda;

        while (f->Direita != NULL) {
          f = f->Direita;
        }

        remove->info = f->info;
        f->info = valor;
        remove->Esquerda = Remover(remove->Esquerda, valor);
      }
    }

    return remove;
  }

  void Imprime(Arvore *tree) {
    if (tree != NULL) {
      tree->Imprime(tree->Esquerda);
      std::cout << tree->info << " - ";
      tree->Imprime(tree->Direita);
    }
  }
};

int main() {
  Arvore *arvore = NULL;

  arvore = arvore->Inserir(arvore, 5);
  arvore = arvore->Inserir(arvore, 7);
  arvore = arvore->Inserir(arvore, 2);
  arvore = arvore->Inserir(arvore, 11);
  arvore = arvore->Inserir(arvore, 13);

  arvore->Imprime(arvore);
  std::cout << "Cabou \n";

  arvore->Remover(arvore, 11);
  arvore->Imprime(arvore);
  std::cout << "Cabou \n";

  Arvore *carvalho = arvore->Buscar(arvore, 12);
  if (carvalho != NULL) {
    std::cout << carvalho->info;
  } else {
    std::cout << "Este valor nao existe na arvore";
  }
}