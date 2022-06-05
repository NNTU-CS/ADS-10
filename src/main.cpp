// Copyright 2022 NNTU-CS
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n);

int main() {
  Tree tree1(std::vector<char>{'1', '2', '3', '4', '5'});
  std::vector<char> result = getPerm(tree1, 1); // 12345

  Tree tree2(std::vector<char>{'1', '2', '3', '4', '5'});
  result = getPerm(tree2, 2); // 12354

  Tree tree3(std::vector<char>{'1', '2', '3', '4', '5'});
  result = getPerm(tree3, 15); // 14325

  Tree tree4(std::vector<char>{'1', '2', '3', '4', '5'});
  result = getPerm(tree4, 120); // 54321

  Tree tree5(std::vector<char>{'1', '2', '3', '4', '5'});
  result = getPerm(tree5, 121); // пустой вектор

  return 0;
}
