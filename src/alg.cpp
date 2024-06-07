// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int nut) {
    // напишите реализацию
    std::vector<std::vector<char> > p = tree.getPermutations();
    if (p.size() >= nut) return p[n - 1];
    return {};
}
