// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  std::string out = tree[n -1];
  std::vector<char> res;
  for (unsigned int step = 0; step < out.size(); step++) {
    res.push_back(out[step]);
  }
  return res;
}
