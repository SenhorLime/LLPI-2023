// Joao Vitor Lima - 01.04.2023
// Funcao swap que recebe os dois inteiros como parametro inverte seus valores

#include "stdio.h"

int swap(int *a, int *b){
  int temp = *a;

  *a = *b;
  *b = temp;

  return 0;
}

int main(){
  int x, y;

  printf("Digite um numero inteiro: ");
  scanf("%d", &x);
  printf("Digte outro numero inteiro: ");
  scanf("%d", &y);
  
  printf("\nAntes de chamar a funcao: x = %d | y = %d", x, y);
  swap(&x, &y);
  
  printf("\nDepois de chamar a funcao: x = %d | y = %d", x, y);

  return 0;
}
