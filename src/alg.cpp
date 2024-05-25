// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include <vector>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPermutationByIndex(const PermutationTree &tree, int index) {
    std::vector<std::vector<char>> permutations = tree.getAllPermutations();
    size_t size = permutations.size();
    std::vector<char> result;

    while (index > 0) {
        result = permutations[index - 1];
    }
    return result;
}
