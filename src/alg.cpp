// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const PermutationTree& tree, int n) {
  std::vector<char> result;
  if (tree.permutations.size() < n) {
    result.push_back('1');
    result.clear();
  } else {
    result = tree.permutations[n - 1];
    std::reverse(result.begin(), result.end());
    result.pop_back();
    std::reverse(result.begin(), result.end());
  }
  return result;
}
