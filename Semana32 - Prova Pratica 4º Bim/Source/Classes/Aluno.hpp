#include <string>
#include <sstream>
#include <iostream>

class Aluno {
public:
    int matricula;
    std::string nome;
    std::string sobrenome;

public:
    Aluno() = default;

    Aluno(int matricula) {
      this->matricula = matricula;
      nome = "";
      sobrenome = "";
    }

    Aluno(int matricula, std::string &nome, std::string &sobrenome) {
      this->matricula = matricula;
      this->nome = nome;
      this->sobrenome = sobrenome;
    }

    Aluno(const std::string &fileLine, char delimiter = ',') {
      std::string data;
      std::stringstream dataLine(fileLine);

      std::getline(dataLine, data, delimiter);
      matricula = std::stoi(data);

      std::getline(dataLine, data, delimiter);
      nome = (data);

      std::getline(dataLine, data, delimiter);
      sobrenome = (data);
    }

    std::string toString() const {
      std::stringstream data;

      data << " [ " << matricula << " | " << nome << " | " << sobrenome << " ] " << std::endl;

      return data.str();
    }

    int operator%(const int &num) const { return matricula % num; }

    bool operator==(const int &num) const { return matricula == num; }

    bool operator>(const Aluno &outroAluno) const { return matricula > outroAluno.matricula; }

    bool operator<(const Aluno &outroAluno) const { return matricula < outroAluno.matricula; }

    bool operator==(const Aluno &outroAluno) const { return matricula == outroAluno.matricula; }

    bool operator!=(const Aluno &outroAluno) const { return matricula != outroAluno.matricula; }

    friend std::ostream &operator<<(std::ostream &output, Aluno &aluno) {
      output << aluno.toString();

      return output;
    }
};