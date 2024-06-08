// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int r) {
    std::vector<std::vector<char> > p = tree.getPermutations();
    if (p.size() >= r) return p[r - 1];
    return {};
}