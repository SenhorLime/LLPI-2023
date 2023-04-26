// Joao Vitor Lima - 01.04.2023
// Esse programa calcula a determinante de uma matriz 2*2 

#include "stdio.h"

int main(){
  int matriz[2][2];
  int determinante;
  int i, j;

  for (i = 0; i < 2; i++){
    for (j = 0; j < 2; j++){
      printf("Elemento [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  determinante = (matriz[0][0] * matriz[1][1]) - (matriz[1][0] * matriz [0][1]);

  printf("O determinante da matriz informada e: %d", determinante);

  return 0;
}
