#ifndef SEMANA_35_MAMIFEROS_HPP
#define SEMANA_35_MAMIFEROS_HPP

#include <string>
#include <iostream>

class Mamiferos {
public:
    std::string nome;
    int idade;

protected:
    int mamas;
    std::string corDosOlhos;

public:
    void aleitar() {
        std::cout << "Funcao Mamifero.aleitar() chamada" << std::endl;
    }

    virtual std::string comunicar() {
        return "Funcao Mamifero.comunicar() chamada";
    }
};

#endif //SEMANA_35_MAMIFEROS_HPP
