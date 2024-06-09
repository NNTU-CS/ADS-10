// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> comb;
    Tree temp = tree;
    return CreateDigit(temp.gethost(), n - 1, comb);
}

std::vector<char> CreateDigit(Leaf* curs, \
    int n, std::vector<char> comb) {
    if (curs->leaves.size() == 0) {
        return comb;
    } else {
        int LarGroup = factor(curs->leaves.size() - 1);
        int position = n / LarGroup;
        if (position >= curs->leaves.size()) {
            std::vector<char> emptyVect;
            return emptyVect;
        }
        comb.push_back(curs->leaves[position]->symb);
        return CreateDigit(curs->leaves[position], \
            n % LarGroup, comb);
    }
}

int factor(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factor(n - 1);
    }
}
