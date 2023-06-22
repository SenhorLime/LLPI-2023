#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Tree {
private:
  const static int root = 0;
  int vetTree[15];

public:
  Tree() {
    for (int i = 0; i < 15; i++) {
      vetTree[i] = 0;
    }
  }
  
  // Create Root Tree
  void Root(int key) {
    vetTree[0] = key;
  }

  // Create Left son of the Root
  void setLeft(int key, int root) {
    int t = (root * 2) + 1;

    vetTree[t] = key;
  }
  
  // Create Right son of the Root
  void setRight(int key, int root) {
    int t = (root * 2) + 2;

    vetTree[t] = key;
  }

  void printTree() {
    cout << "[ ";

    for (int i = 0; i < 15; i++) {
      if (vetTree[i] != 0) {
        cout << (vetTree[i]) << " - ";
      }
    }

    cout << " ]";
  }
};
#endif
