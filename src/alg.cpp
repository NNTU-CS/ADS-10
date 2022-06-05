// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> g;
  std::string permutation = tree.gPermut(n);
  if (permutation.length() == 0) {
    return g;
  }
  g.resize(permutation.length(), ' ');
  int x = 0;
  while (true) {
    if (permutation.length() == 0) {
      return g;
    } else {
      g[x++] = permutation[0];
      permutation.erase(permutation.begin());
    }
  }
}
