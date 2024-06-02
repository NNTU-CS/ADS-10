// Copyright 2022 NNTU-CS
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n);

int main() {
  // определяем входной вектор для дерева
  std::vector<char> in = {'1', '2', '3'};

  // создаем дерево
  Tree tree(in);

  // запрашиваем первую перестановку
  std::vector<char> result1 = getPerm(tree, 1);  //  123

  // запрашиваем вторую перестановку
  std::vector<char> result2 = getPerm(tree, 2);  //  132
  return 0;
}
