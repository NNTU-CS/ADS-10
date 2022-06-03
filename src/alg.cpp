// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string w = tree.permutt(n);
  std::vector<char> vec;
  if (!w.length()) {
    return vec;
  }
  vec.resize(w.length(), ' ');
  int i = 0;
  while (w.length() != 0) {
    vec[i] = w[0];
    ++i;
    w.erase(w.begin());
  }
  return vec;
}


