// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  if (n < 1 || n > tree.getPermutations().size()) {
    return {};
  }
  std::string permStr = tree.getPermutations()[n - 1];
  std::vector<char> permVec(permStr.begin(), permStr.end());
  permVec.erase(permVec.begin());
  return permVec;
}
