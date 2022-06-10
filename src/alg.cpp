// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string th = tree[n-1];
  std::vector<char> result;
  for (int i = 0; i < th.length(); ++i) {
    result.push_back(th[i]);
  }
  return result;
}
