// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  int c = n - 1;
  std::string Razm = tree[c];
  std::vector<char> Kol;
  int a;
  for (a = 0; a < Razm.length(); a++) {
    Kol.push_back(Razm[a]);
  }
  return Kol;
}
