// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string q = tree[n - 1];
  std::vector<char> list;
  for (int i = 0; i < q.length(); i++) {
    list.push_back(q[i]);
  }
  return list;
}
