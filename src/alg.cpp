// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<std::vector<char>> permutations = tree.getPermutations();
  if (n > permutations.size() || n < 1)
    return {};
  return permutations[n - 1];
}
