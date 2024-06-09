// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>

#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<std::vector<char>> all_permutations = tree.getPermutations();
  if (n < 1 || n > all_permutations.size()) {
    return {};
  }
  return all_permutations[n - 1];
}
