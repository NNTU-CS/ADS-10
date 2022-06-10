// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  std::string qwe = tree.storage(n - 1);
  std::vector<char> result;
  for (int m = 0; m < qwe.size(); ++m) {
      result.push_back(qwe[m]);
  }
  return result;
}
