// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> kol;
    Tree temp = tree;
    return createNumber(temp.getRoot(), n - 1, kol);
}

std::vector<char> createNumber(stem* cur, int n, std::vector<char> kol) {
    if (cur->leaves.size() == 0) {
        return kol;
    } else {
        int group = factorial(cur->leaves.size() - 1);
        int pos = n / group;
        if (pos >= cur->leaves.size()) {
            std::vector<char> emptyVec;
            return emptyVec;
        }
        kol.push_back(cur->leaves[pos]->symbol);
        return createNumber(cur->leaves[pos], n % group, kol);
    }
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
