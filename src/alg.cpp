// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getperm(Node* node, int& n, std::vector<char>& permutation) {
  if (n == 0) {
    return permutation;
  }
  for (Node* child : node->children) {
    permutation.push_back(child->data);
    std::vector<char> result = getperm(child, --n, permutation);
    if (!result.empty()) {
      return result;
    }
    permutation.pop_back();
  }
  return {};
}
