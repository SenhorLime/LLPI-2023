#ifndef SEMANA_35_CAO_HPP
#define SEMANA_35_CAO_HPP

#include "Mamiferos.hpp"

class Cao : public Mamiferos {
private:
    int tamanhoCauda;

public:
    void morder() {
        std::cout << "Funcao Cao.morder chamada" << std::endl;
    }

    std::string comunicar() {
        return "Funcao Cao.comunicar() chamada";
    }

};

#endif //SEMANA_35_CAO_HPP
