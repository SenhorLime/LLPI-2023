// Joao Vitor Lima - 02.04.2023
// O programa mostra a diferenca entre p++, (*p)++ e *(p++)

#include "stdio.h"

int main() {
  int x = 3;
  int *p;
  p = &x;

  printf("p++: %d", p++);            // Incrementa o ponteiro primeiro 
  printf("\n(*p)++: %d", (*p)++);   // Incrementa o valor primeiro
  printf("\n*(p++): %d", *(p++));  // Incrementa o ponteiro primeiro e depois obtem o valor
  
  return 0;
}
