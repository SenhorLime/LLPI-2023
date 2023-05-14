# Bolinhas com OOP + SFML
#### Minha primeira atividade usando SFML em C++

Este programa é um programa simples usando a biblioteca SFML para renderizar múltiplas bolinhas coloridas em uma janela.

## Explicação do programa
### Classes
- ```Ball```: Esta classe representa uma bolinha no programa. Ela possui membros privados que armazenam o tamanho, posição, velocidade e cor da bolinha, que são gerados aleatoriamente. Além disso, possui métodos públicos para definir a velocidade e a posição da bolinha, bem como um método para renderizá-la na janela.

### Principal Função
- ```main```: A função principal do programa inicializa a janela, cria um vetor de objetos ```Ball``` e entra em um loop principal. Dentro desse loop, o programa renderiza cada bolinha do vetor e atualiza a exibição na janela.

## Notas
- O programa foi desenvolvido utilizando o editor LunarVim e foi testado apenas no Fedora Linux 37 (KDE Spin) com Kernel 6.2.14
- Para compilação foram utilizados tanto o G++ quanto o Clang++. Certifique de ter um dos comipiladores instalados no seu sistema

## Rodando Localmente

#### Requisitos
- SFML 2.5.1
- Clang 15.0.7 ou GCC 12.2.1

--- 

1. Clone o repositiorio

```
git clone https://github.com/SenhorLime/LLPI-2023.git
cd 'Semana10 - SFML e Classes'
```

2. Compile o programa
- Usando o G++
```
g++ main.cpp -o a.out -lsfml-system -lsfml-window -lsfml-graphics
```
- Usando o Clang++
```
g++ main.cpp -o a.out -lsfml-system -lsfml-window -lsfml-graphics
```

3. Execute o programa
```
./a.out
```
**Lembre-se de que o programa foi testado apenas no ambiente mencionado, e pode ser necessário ajustá-lo para funcionar em outras configurações.**