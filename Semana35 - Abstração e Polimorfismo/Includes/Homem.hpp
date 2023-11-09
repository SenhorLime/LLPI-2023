#ifndef SEMANA_35_HOMEM_HPP
#define SEMANA_35_HOMEM_HPP

#include "Mamiferos.hpp"

class Homem : public Mamiferos {
private:
    bool casado;

public:
    void rir() {
        std::cout << "Funcao Homem.rir() chamada" << std::endl;
    }

    std::string comunicar() {
        return "Funcao Homem.comunicar() chamada";
    }

};

#endif //SEMANA_35_HOMEM_HPP
