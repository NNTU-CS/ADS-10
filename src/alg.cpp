// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> perm;
        if (tree.permutations.size() < n) {
        perm.push_back('1');
        perm.clear();
    } else {
        perm = tree.permutations[n - 1];
        reverse(perm.begin(), perm.end());
        perm.pop_back();
        reverse(perm.begin(), perm.end());
    }
    return perm;
}
