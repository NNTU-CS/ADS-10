// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> perm = tree.getPermut();
    if (n < 0 || perm.size() < n) {
        return {};
    }
    std::vector<char> temp = perm[n - 1];
    temp.erase(temp.begin());
    return temp;
}
