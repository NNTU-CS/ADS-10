// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> g;
  std::string perm = tree.gPermut(n);
  if (perm.length() == 0) {
    return g;
  }
  g.resize(perm.length(), ' ');
  int i = 0;
  while (true) {
    if (perm.length() == 0) {
      return g;
    } else {
      g[i++] = perm[0];
      perm.erase(perm.begin());
    }
  }
}
