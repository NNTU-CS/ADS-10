// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  int b = n - 1;
  std::string Razm = tree[b];
  std::vector<char> Kol;
  int i;
  for (i = 0; i < Razm.length(); i++) {
    Kol.push_back(Razm[i]);
  }
  return Kol;
}
