// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std :: vector<char> result;
  for (int i = 0; i < tree[n - 1].length(); i++)
    result.push_back(tree[n - 1][i]);
  return result;
}
