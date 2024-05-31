// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <vector>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    if (n < 0 || n >= static_cast<int>(tree.allPermutations.size())) {
    return {};
  }
  return tree.allPermutations[n];
}
