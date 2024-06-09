// Copyright 2022 NNTU-CS
#include <vector>
#include <iostream>
#include "tree.h"

std::vector<char> fetchPermutation(const Tree& tree, int index);

int main() {
    std::vector<char> symbols = {'A', 'B', 'C'};
    Tree tree(symbols);

    std::vector<char> firstPerm = fetchPermutation(tree, 1);
    std::vector<char> thirdPerm = fetchPermutation(tree, 3);

    for (char c : firstPerm) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for (char c : thirdPerm) {
        std::cout << c << " ";
    }

    return 0;
}

std::vector<char> fetchPermutation(const Tree& tree, int index) {
    return tree.getPermutation(index);
}

