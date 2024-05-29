// Copyright 2022 NNTU-CS
#include  <iostream>
#include <vector>
#include <algorithm>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<std::string> allPermutations = getAllPermutations(tree);
    if (index <= allPermutations.size()) {
        std::string perm = allPermutations[index - 1];
        return std::vector<char>(perm.begin(), perm.end());
    } else {
        return std::vector<char>();
    }
}
