// Joao Vitor Lima 
// Data de Inicio - 02.04.2023 || Data de Termino - 26.04.2023 (Enrolei um pouquinho para terminar)
// Atividade sobre arquivos de texto (Primeira vez fazendo isso)
// Tem que abrir o arquivo FaroesteCaboclo.txt em modo de leitura e pedir ao usuario uma palavra para procurar dentro do arquivo
// No final tem que mostrar quantas vezes esse palavra foi digitada
// Depois abrir o arquivo novamente e pedir ao usuario uma palavra que vai ser substituida por outra em todo o texto

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Funcao para contar as palavras que recebe como parametros o nome do arquivo e a palavra que vai ser contabilizada
int countWord (char *fileName, char *word){
  // Declaracao de variaveis 
  FILE *file;
  char line[1000];
  int wordCounter = 0;

  file = fopen(fileName, "r"); // Abre o arquivo
  if (file == NULL) {
    printf("Deu ruim na hora de abrir o arquivo meu bom"); // Mensagem de erro se o arquivo nao existir
    return -1;
  }
  
  // Loop que realiza a contagem das palavras
  while (fgets (line, 1000, file) != NULL) { 
    char *token = strtok(line, " \t\n"); // Define quando tem uma quebra de linha ou espaco no arquivo 
    while (token != NULL) {
      if (strcmp(token, word) == 0) { 
        wordCounter++;
      }
      token = strtok(NULL, " \t\n");
    }
  }
  fclose(file); 

  return wordCounter; // Retorna a quantidade de vezes que a palavra apareceu
}

// Funcao para trocar as palavras do arquivo, mas essa mudanca e feita em outro arquivo
void replaceWordInFile (char *fileName, char *newFileName, char *oldWord, char *newWord){
  // Declaracao de variaveis
  FILE *inputFile, *outputFile;
  char read[100], character;
  int wordLength;
  
  inputFile = fopen(fileName, "r");
  outputFile = fopen(newFileName, "w+");
  if (inputFile == NULL || outputFile == NULL){
    printf("Deu ruim na hora de abrir o arquivo meu bom"); // Gostei dessa mensagem de erro
    exit(0);
  }

  rewind(inputFile);
  while (!feof(inputFile)){ // Loop enquanto o final do arquivo nao chega
    fscanf(inputFile, "%s", read);
    if (strcmp(read, oldWord) == 0){
      strcpy(read, newWord);
    }
    fprintf(outputFile, "%s", read);
  }

  rewind(outputFile);
  while (1){
    character = fgetc(outputFile);
    if (character == EOF){
      break;
    }
  }

  fclose(inputFile);
  fclose(outputFile);
}

int main (){
  char fileName[100] = "FaroesteCaboclo.txt";
  char newFileName[100] = "FaroesteCabocloNew.txt";
  char oldWord[100], newWord[100], wordSearch[100];
  int wordCounter;
  
  printf("Digite qual palavra deseja buscar na letra da musica Faroeste Cabloco: ");
  scanf("%s", wordSearch);

  wordCounter = countWord(fileName, wordSearch);
  printf("A palavra '%s' aparece %d vezes no arquivo", wordSearch, wordCounter);

  printf("\nDigite a palavra para substituir no arquivo: ");
  scanf("%s", oldWord);
  printf("Digite a palavra que vai ir no lugar a anterior: ");
  scanf("%s", newWord);
  replaceWordInFile(fileName, newFileName, oldWord, newWord);

  printf("\nTeoricamente deu certo a troca dos nomes no arquivo");
  return 0;
}
