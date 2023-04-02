// Joao Vitor Lima - 01.04.2023
// Programa que exibe o valor das variaveis apos operacoes usando operadores bit a bit

#include "stdio.h"

int main (){
  int x = 2, y = 4;

  printf("\n%d", x & y); // 0
  printf("\n%d", x | y); // 6
  printf("\n%d", x ^ y); // 6
  printf("\n%d", ~x); // -3
  printf("\n%d", x << 3); // 16
  printf("\n%d", x >> 1); // 1

  return 0;
}
