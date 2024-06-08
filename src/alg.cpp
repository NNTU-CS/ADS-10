// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
#include <vector>

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> permutation;
    const Node* current = node;

    while (!current->children.empty()) {
        int total_permutations = current->children[0]->num_permutations;

        int index = n / (total_permutations / current->children.size());
        n %= (total_permutations / current->children.size());

        permutation.push_back(current->children[index]->data);
        current = current->children[index];
    }

    return permutation;
}
