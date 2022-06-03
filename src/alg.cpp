// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  std::string a = tree[n - 1];
  std::vector <char> reslt;
  int b = 0;
  while (b < a.length()) {
    reslt.push_back(a[b]);
    b++;
  }
  return reslt;
}

