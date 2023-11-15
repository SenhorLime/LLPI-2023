#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class FileManager {
public:
    static std::vector<std::string> loadFile(const std::string &path) {
      std::string line;
      std::vector<std::string> lines;

      std::ifstream file(path.c_str());

      if (file.is_open()) {
        std::getline(file, line);

        while (std::getline(file, line)) {
          lines.push_back(line);
        }
      } else { std::cerr << "Could not open file" << std::endl; }

      return lines;
    }

    static bool writeLineInFile(const std::string &path, const std::string &line, bool add) {
      std::ofstream file;

      if (add) {
        file.open(path, std::ios::app);
      } else { file.open(path); }

      if (!file.is_open()) {
        std::cerr << "Could not open file" << std::endl;
        return false;
      }

      file << line << std::endl;

      file.close();
      return true;
    }

    static bool writeVectorInFile(const std::string &path, const std::vector<std::string> &lines, bool add) {
      std::ofstream file;

      if (add) {
        file.open(path, std::ios::app);
      } else { file.open(path); }

      if (!file.is_open()) { std::cerr << "Could not open file" << std::endl; }

      for (const auto &line: lines) { file << line << std::endl; }

      file.close();
      return true;
    }
};

#endif //FILEMANAGER_HPP
