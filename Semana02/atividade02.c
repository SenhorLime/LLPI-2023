// Joao Vitor Lima - 01.04.2023
// Programa que le duas strings ate que sejam iguais e no final mostra a concatenacao de todas, e o tamanho da maior e da menor

#include "stdio.h"
#include "string.h"

#define tam 500

int main (){
  char str1[tam];
  char str2[tam];
  char totalStr[tam];
  int maiorString = 0, menorString;
  
  do { // Realiza as acoes dentro do bloco de repeticao enquanto duas string nao forem iguais
    printf("Digite a primeira string: ");
    scanf("%s", str1);
    strcat(totalStr, str1); // Concatena todas as strings digitadas ate agora

    printf("Digite a segunda string: ");
    scanf("%s", str2);
    strcat(totalStr, str2);
    
    if ( strlen(str1) > strlen(str2) ){     // Testa se a string1 e maior que a string2 
      if ( strlen(str1) > maiorString ){   // Se o teste anterior for verdade, testa se a string1 e maior que o valor da maior string
        maiorString = strlen(str1);       // Se for verdade da o valor da string1 para a maior string
      } 
    } else if ( strlen(str1) < strlen(str2) ){
      menorString = strlen(str1);
    }

    if ( strlen(str2) > strlen(str1) ){     // Testa se a string2 e maior que a string1
      if( strlen(str1) > maiorString ) {   // Se o teste anterior for verdade, testa se a string2 e maior que o valor da maior string
        maiorString = strlen(str2);       // Se for verdade, da o valor da string2 para a maior string
      }
    } else if (strlen(str2) < strlen(str1) ) {
      menorString = strlen(str2);
    }

  } while(strcmp(str1, str2) != 0);
  
  printf("\nTodas as strings digitadas contatenadas: %s", totalStr);
  printf("\nNumero de caracteres da maior string: %d", maiorString);
  printf("\nNumero de caracteres da menor string: %d", menorString);

  return 0;
}
