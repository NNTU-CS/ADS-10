// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

  using std::vector;
vector<char> getPerm(const Tree& trea, int kk) {
  vector<char> resulll;
  for (int i = 0; i < trea[kk - 1].length(); i++) {
  resulll.push_back(trea[kk - 1][i]);
  }
  return resulll;
}

