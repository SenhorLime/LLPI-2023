// Joao Vitor Lima - 02.04.2023
// Atividade sobre arquivos de texto (Primeira vez fazendo isso)
// Tem que abrir o arquivo FaroesteCaboclo.txt em modo de leitura e pedir ao usuario uma palavra para procurar dentro do arquivo
// No final tem que mostrar quantas vezes esse palavra foi digitada
// Depois abrir o arquivo novamente e pedir ao usuario uma palavra que vai ser substituida por outra em todo o texto

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int countWord (char *fileName, char *word){
  FILE *file;
  char line[1000];
  int wordCounter = 0;

  file = fopen(fileName, "r");

  if (file == NULL) {
    printf("Deu ruim na hora de abrir o arquivo meu bom");
    return -1;
  }

  while (fgets (line, 1000, file) != NULL) {
    char *token = strtok(line, " \t\n");

    while (token != NULL) {
      if (strcmp(token, word) == 0) {
        wordCounter++;
      }

      token = strtok(NULL, " \t\n");
    }
  }

  fclose(file);

  return wordCounter;
}

int main (){
  char fileName[100] = "FaroesteCaboclo.txt";
  char wordSearch[100];
  int wordCounter;


  printf("Digite qual palavra deseja buscar na letra da musica Faroeste Cabloco: ");
  scanf("%s", wordSearch);

  wordCounter = countWord(fileName, wordSearch);

  printf("\nA palavra '%s' aparece %d vez no arquivo", wordSearch, wordCounter);
}
