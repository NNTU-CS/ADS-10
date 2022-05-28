// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string a = tree[n - 1];
  std::vector<char> perm;
  int x = 0;
  while (x < a.length()) {
    perm.push_back(a[x]);
    ++x;
  }
  return perm;
}
