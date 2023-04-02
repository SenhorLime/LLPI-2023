**Aluno: João Vitor Lima**
**Data: 02.04.2023**

#### Questão 2 - Discuta, passo a passo, o efeito do seguinte fragmento de código:
---
##### a) int *p, *q;
O fragmento de código acima define dois ponteiros para inteiros.

---
##### b) p = malloc (sizeof (int));
O fragmento de código acima aloca espaço na memória para armazenar um inteiro.

---
##### c) *p = 123;
O fragmento de código acima muda o valor de uma variável utilizando um ponteiro que está armazendo o seu local na memória.

---
##### d) q = malloc (sizeof (int));
O mesmo da segunda pergunta, aloca espaço na memória para armazenar um inteiro.

---
##### e) *q = *p;
O fragmento de código usa o ponteiro 'q' para mudar o valor da variável que o ponteiro 'p' está apontando.

---
##### f) q = p;
O fragmento acima atribui o valor da variável 'q' para a variável 'p'.

---
##### g) free (p);
Libera o espaço de memória alocado para variável 'p'.

---
##### h) free (q); // má ideia...
Esse comando é uma má ideia porque 'q' aponta para o mesmo espaço de memória que 'p', espaço esse que já foi liberado anteriormente, podende causar erros no programa por liberar a memória novamente.

---
##### i) q = NULL; // boa ideia
Atribuir o valor a 'q' é uma boa ideia já que ele aponta para uma posição na memória que agora está inválida.