#include <iostream>
#include <vector>

#include "Includes/Mamiferos.hpp"
#include "Includes/Homem.hpp"
#include "Includes/Cao.hpp"
#include "Includes/Gato.hpp"

int main() {
    std::vector<Mamiferos *> mamiferosVector;

    mamiferosVector.push_back(new Mamiferos);
    mamiferosVector.push_back(new Homem);
    mamiferosVector.push_back(new Cao);
    mamiferosVector.push_back(new Gato);

    for (std::vector<Mamiferos *>::iterator it = mamiferosVector.begin(); it != mamiferosVector.end(); it++) {
        std::cout << (*it)->comunicar() << std::endl;
    }
}
