//============================================================================
// Name        : Classe de dado Aluno
// Author      : Alisson RS
// Description : Atividade de avaliação de métodos de ordenação.
//============================================================================


#include <cstdlib>
#include <iostream>
#include <string>
#include "estruturado.hpp"
#include "classe.hpp"

using namespace std;

int main(int argc, char** argv) {
    int escolha;

    do {
        // Apresenta o menu
        std::cout << "MENU:" << std::endl;
        std::cout << "1. main classe.hpp" << std::endl;
        std::cout << "2. main estruturado.hpp" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        // Realiza a ação de acordo com a escolha do usuário
        switch (escolha) {
            case 1:
                main1(argc,argv);
                break;
            case 2:
            	main2(argc,argv);
                break;
            case 0:
                std::cout << "Saindo do programa." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
                break;
        }
    } while (escolha != 0);

    return 0;
}
