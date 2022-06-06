// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string first = tree[n - 1];
  std::vector<char> changes;
  for (int i = 0; i < first.length(); i++) {
    changes.push_back(first[i]);
  }
  return changes;
}
