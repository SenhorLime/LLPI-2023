#ifndef SEMANA_35_GATO_HPP
#define SEMANA_35_GATO_HPP

#include "Mamiferos.hpp"

class Gato : public Mamiferos {
private:
    int tamanhoCauda;

public:
    std::string arranhar() {
        return "Funcao Gato.arranhar() chamada";
    }
};

#endif //SEMANA_35_GATO_HPP
