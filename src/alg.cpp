// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  std::vector<char> list;
  std::string nowtree = tree[n - 1];
  for (int x = 0; x < nowtree.length(); x++) {
    list.push_back(nowtree[x]);
  }
  return list;
}
