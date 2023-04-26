// Joao Vitor Lima - 02.04.2023
// Uma funcao que recebe um array de 10 posicoes e multiplica cada elemento por 2, no final mostra o array duplicado e o array antes da duplicacao

#include "stdio.h"
#include "stdlib.h"

void multiplicaPorDois (int vetor[]) {
  int i;

  for(i = 0; i < 10; i++) {
    vetor[i] *= 2;
  }
}

int main() {
  int i, vetor[10];
  
  printf("Vetor antes de chamar a funcao: ");
  for(i = 0; i < 10; i++) {
    printf("%d - ", vetor[i] = rand() % 30);
  }

  multiplicaPorDois(vetor);

  printf("\nVetor depois de chamar a funcao: ");
  for(i = 0; i < 10; i++) {
    printf("%d - ", vetor[i]);
  }

  return 0;
}
