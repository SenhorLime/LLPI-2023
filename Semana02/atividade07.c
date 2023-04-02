// Joao Vitor Lima - 02.04.2023
// Fazendo o codigo do exemplo para descobrir qual valor vai ser impresso no final

#include "stdio.h"

int main(){
  int y, x, *p;

  y = 0;
  p = &y;
  x = *p;
  x = 4;
  (*p)++;
  x--;
  (*p) += x;

  printf("y = %d", y);

  return 0;
}
