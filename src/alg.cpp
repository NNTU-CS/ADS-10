// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string k = tree[n - 1];
  std::vector<char> perm;
  for (int i = 0; i < k.length(); i++) {
    perm.push_back(k[i]);
  }
  return perm;// напишите реализацию
}
