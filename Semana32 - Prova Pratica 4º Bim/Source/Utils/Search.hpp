#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename T>
class Dicionario {
public:
    std::vector<T> dicionarioVector;

public:
    Dicionario() = default;

    ~Dicionario() { dicionarioVector.clear(); }

public:
    void insert(T object) {
      dicionarioVector.push_back(object);
    }

    int findLinear(T key) {
      std::sort (dicionarioVector.begin(), dicionarioVector.end());

      for (auto i = 0; i < dicionarioVector.size(); i++) {
        if (dicionarioVector.at(i) == key) { return i; }
      }

      return -1;
    }

    int findBinary(T key) {
      std::sort (dicionarioVector.begin(), dicionarioVector.end());

      return findBinary(0, dicionarioVector.size() - 1, key);
    }

private:
    int findBinary(int esquerda, int direita, T key) {
      int meio = (esquerda + direita) / 2;

      if (dicionarioVector.at(meio) && esquerda >= direita) {
        return -1;
      } else if (key > dicionarioVector.at(meio)) {
        return (findBinary(meio + 1, direita, key));
      } else if (key < dicionarioVector.at(meio)) {
        return findBinary(esquerda, meio - 1, key);
      } else {
        return meio;
      }
    }
};


#endif //SEARCH_HPP
