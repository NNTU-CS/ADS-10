// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

using std::vector;
vector<char> getPerm(const Tree& tr, int k) {
  vector<char> resultat;
  for (int j = 0; j < tr[k - 1].length(); j++) {
  resultat.push_back(tr[k - 1][j]);
  }
  return resultat;
}
