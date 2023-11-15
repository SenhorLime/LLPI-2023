#ifndef SEMANA32_HASHTABLE_HPP
#define SEMANA32_HASHTABLE_HPP

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class Cell {
public:
    T key;

    Cell(T key) { this->key = key; }

    bool operator>(const Cell &otherCell) { return key > otherCell.key; }

    bool operator<(const Cell &otherCell) { return key < otherCell.key; }

    bool operator==(const Cell &otherCell) { return key == otherCell.key; }
};

template<typename T>
class HashTable {
private:
    int size;
    std::vector<std::vector<Cell<T> > > table;

private:
    int getMod(T key) { return key % size; }

    int searchList(std::vector<Cell<T> > list, T key) {
      std::sort(list.begin(), list.end());

      for (auto i = 0; i < list.size(); i++) {
        if (list.at(i) == key) {
          return i;
        }
      }

      return -1;
    }

    T removeList(std::vector<Cell<T> > list, T key) {
      list.erase(searchList(list, key));

      return key;
    }

    void printList(std::vector<Cell<T> > list) {
      for (typename std::vector<Cell<T> >::iterator it = list.begin(); it != list.end(); it++) {
        std::cout << list.at(*it);

        if (it != list.size()) { std::cout << " - "; }
      }
    }

public:
    HashTable(int size) {
      this->size = size;

      for (int i = 0; i < size; i++) {
        std::vector<Cell<T>> list;
        table.push_back(list);
      }
    }

    T search(T key) {
      int i = this->getMod(key);

      if (table.at(i).empty()) {
        return -1;
      } else {
        int item = searchList(table[i], key);

        if (item == -1) {
          return item;
        } else { return table.at(i).at(item).key; }
      }
    }

    void insert(T key) {
      int i = getMod(key);

      table.at(i).push_back(key);
    }

    T remove(T key) {
      int i = getMod(key);
      T item = removeList(table.at(i), key);

      if (item == -1) {
        std::cout << "Registro nao presente -> " << key << std::endl;
        return -1;
      } else { return item; }
    }

    void print() {
      std::cout << "Hash de Modulo % " << size << std::endl;

      for (int i = 0; i < size; i++) {
        std::cout << "h = " << i << " [ ";
        printList(table.at(i));
        std::cout << " ]" << std::endl;
      }
    }
};

#endif
