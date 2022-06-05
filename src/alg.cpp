// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string e = tree[n - 1];
  std::vector <char> resultat;
  int g = 0;
  while (g < e.length()) {
    resultat.push_back(e[g]);
    g++;
  }
  return resultat;
}
