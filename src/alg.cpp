// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <vector>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> out;
  std::string perm = tree.get(n-1);

  for (int i = 0; i < perm.size(); i++) {
    out.push_back(perm[i]);
  }
  return out;
}
