// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n);

void printVector(const std::vector<char>&vec) {
    for (char ch : vec) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

int main() {
  // определяем входной вектор для дерева
  std::vector<char> in = {'1', '2', '3'};

  // создаем дерево
  Tree tree(in);
  std::vector<char> result = getPerm(tree, 6);
  std::cout << "Permutation #" << 1 << ": ";
  printVector(result);

  // запрашиваем первую перестановку
  std::vector<char> result1 = getPerm(tree, 1);//  123
  printVector(result1);

  // запрашиваем вторую перестановку
  std::vector<char> result2 = getPerm(tree, 2);  //  132
  printVector(result2);
  return 0;
}
