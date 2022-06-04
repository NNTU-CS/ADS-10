// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string optsTree = tree[n - 1];
  std::vector<char> numbs;
  for (int k = 0; k < optsTree.length(); k++) {
    numbs.push_back(optsTree[k]);
  }
  return numbs;
}
