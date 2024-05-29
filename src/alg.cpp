// Copyright 2022 NNTU-CS
#include  <iostream>
#include <vector>
#include <algorithm>
#include  "tree.h"

std::vector<char> getPerm(Tree& tree, int index) {
    std::vector<std::string> allPermutations = tree.getAllPermutations();
    if (index <= allPermutations.size()) {
        std::string perm = allPermutations[index - 1];
        return std::vector<char>(perm.begin(), perm.end());
    } else {
        return std::vector<char>();
    }
}
