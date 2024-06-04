// Copyright 2022 NNTU-CS
#include  <vector>
#include  <iostream>
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n);

int main() {
    std::vector<char> symbols = { 'A', 'B', 'C' };
    Tree tree(symbols);
    std::vector<char> perm1 = getPerm(tree, 1); //первая
    std::vector<char> perm2 = getPerm(tree, 3); //третья
    for (char c : perm1) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    for (char c : perm2) {
        std::cout << c << " ";
    }
}
