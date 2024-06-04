// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  if (n > tree.permutations.size()) {
    return {};
  }
  std::vector<char> result = tree.permutations[n - 1];
  std::reverse(result.begin(), result.end());
  result.pop_back();
  std::reverse(result.begin(), result.end());
  return result;
}
