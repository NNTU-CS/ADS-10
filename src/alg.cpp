// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  std::string inp = tree.storage(n - 1);
  std::vector<char> result;
  for (int i = 0; i < inp.size(); ++i) {
      result.push_back(inp[i]);
  }
  return result;
}
