// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string optionsTree = tree[n - 1];
  std::vector<char> nums;
  for (int x = 0; x < optionsTree.length(); x++) {
    nums.push_back(optionsTree[x]);
  }
  return nums;
}
