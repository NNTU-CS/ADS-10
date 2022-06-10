// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  std::string genTree = tree[n - 1];
  std::vector<char> permutation;
  for (int i = 0; i < genTree.length(); i++) {
    permutation.push_back(genTree[i]);
  }
  return permutation;
}
