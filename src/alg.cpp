// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> permutations = tree.getPermutations();
    if (n < 1 || n > permutations.size()) {
        return {};
    }
    return permutations[n - 1];
}
