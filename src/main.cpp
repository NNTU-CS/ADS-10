// Copyright 2022 NNTU-CS
#include "tree.h"

std::vector<char> getPerm(const Drevo& drevo, int n);

int main() {
  // определяем входной вектор для дерева
  std::vector<char> in = {'1', '2', '3'};

  // создаем дерево
  Drevo drevo(in);

  // запрашиваем первую перестановку
  std::vector<char> result1 = getPerm(drevo, 1);  //  123

  // запрашиваем вторую перестановку
  std::vector<char> result2 = getPerm(drevo, 2);  //  132
  return 0;
}
