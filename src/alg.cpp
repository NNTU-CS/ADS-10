// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int t) {
  std::string source = tree[t - 1];
  std::vector<char> perm;
  for (int c = 0; c < source.length(); c++) {
    perm.push_back(source[c]);
  }
  return perm;
}
