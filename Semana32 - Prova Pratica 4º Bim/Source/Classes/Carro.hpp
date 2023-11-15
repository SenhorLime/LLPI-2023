#include <string>
#include <sstream>
#include <iostream>

class Carro {
public:
    int codigo;
    int cilindradas;
    std::string montadora;
    std::string imagem;

public:
    Carro() = default;

    Carro (int codigo) {
      this->codigo = codigo;
      cilindradas = 0;
      montadora = "";
      imagem = "";
    }

    Carro(int codigo, int cilindrada, std::string &montadora, std::string &imagem) {
      this->codigo = codigo;
      this->cilindradas = cilindrada;
      this->montadora = montadora;
      this->imagem = imagem;
    }

    Carro(const std::string &fileLine, char delimiter = ',') {
      std::string data;
      std::stringstream dataLine(fileLine);

      std::getline(dataLine, data, delimiter);
      codigo = std::stoi(data);

      std::getline(dataLine, data, delimiter);
      montadora = (data);

      std::getline(dataLine, data, delimiter);
      cilindradas = std::stoi(data);

      std::getline(dataLine, data, delimiter);
      imagem = (data);
    }

    std::string toString() const {
      std::stringstream data;

      data << " [ " << codigo << " | " << montadora << " | " << cilindradas << " | " << imagem << " ] " << std::endl;

      return data.str();
    }

    int operator%(const int &num) const { return codigo % num; }

    bool operator==(const int &num) const { return codigo == num; }

    bool operator>(const Carro &outroCarro) const { return codigo > outroCarro.codigo; }

    bool operator<(const Carro &outraMoto) const { return codigo < outraMoto.codigo; }

    bool operator==(const Carro &outraMoto) const { return codigo == outraMoto.codigo; }

    bool operator!=(const Carro &outraMoto) const { return codigo != outraMoto.codigo; }

    friend std::ostream &operator<<(std::ostream &output, Carro &carro) {
      output << carro.toString();

      return output;
    }
};