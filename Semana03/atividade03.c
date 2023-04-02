// Joao Vitor Lima - 02.04.2023
// Verificacao de tamanho. Copiar o codigo do exemplo e depois dizer a diferenca entre o primeiro e segunda printf

#include "stdio.h"

typedef struct {
  int dia, mes, ano;
}data;

int main(){
  printf("sizeof(data) = %d", sizeof(data));  );    // Vai exibir 12, que e o tamanho em bytes que a estrutura ocupa
  printf("\nsizeof(data*) = %d", sizeof(data*));   // Vai exibir 8, que e o tamanho em bytes que o ponteiro da estrutura ocupa

  return 0;
}
