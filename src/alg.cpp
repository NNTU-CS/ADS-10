// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> permutations = tree.getAllPermutations();
    size_t size = permutations.size();
    if (n > 0 && n <= size) {
        return permutations[n - 1];
    }
    else {
        return {};
    }
}
