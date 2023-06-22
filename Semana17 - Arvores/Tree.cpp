#include "Tree.hpp"

int main() {
  Tree obj;

  obj.Root(30);
  obj.setLeft(25, 0);
  obj.setRight(40, 0);

  obj.setLeft(15, 1);
  obj.setRight(27, 1);

  obj.setLeft(32, 2);
  obj.setRight(65, 2);
  
  obj.setLeft(5, 3);
  obj.setRight(17, 3);

  obj.setRight(28, 4);

  obj.setLeft(31, 5);
  obj.setRight(38, 5);

  obj.setLeft(50, 6);
  obj.setRight(98, 6);

  obj.printTree();

  return 0;
}
