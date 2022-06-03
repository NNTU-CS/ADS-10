// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string origin = tree[n - 1];
  std::vector<char> prm;
  for (int l = 0; l < origin.length(); l++) {
    prm.push_back(origin[l]);
  }
  return prm;
}
