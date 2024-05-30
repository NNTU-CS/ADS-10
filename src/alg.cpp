// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <vector>
#include  "tree.h"

int fact(int n) {
    if (n == 1) return 1;
    return n * fact(n - 1);
}

void getPermHelper(std::vector<char>& values, int index, std::vector<char>& perm, std::vector<int>& idx) {
    if (values.empty()) {
        return;
    }

    int numChildren = fact(values.size() - 1);
    if (numChildren == 0) {
        perm.push_back(values[0]);
        return;
    }

    int chIndex = getChildIndex(index, numChildren);
    idx.push_back(chIndex);
    index -= chIndex * numChildren;

    std::vector<char> chValues;
    for (int i = 0; i < values.size(); ++i) {
        if (i != idx.back()) {
            chValues.push_back(values[i]);
        }
    }
    getPermHelper(chValues, index, perm, idx);
    perm.push_back(values[idx.back()]);
    idx.pop_back();
}

int getChildIndex(int index, int numCh) {
    int chIndex = index / numCh;
    index -= chIndex * numCh;
    return chIndex;
}

std::vector<char> getPerm(const Tree& tree, int n) {
    if (index < 0 || index >= fact(values.size())) {
        throw std::out_of_range("Invalid index");
    }

    std::vector<char> permutation;
    std::vector<int> indices;
    getPermHelper(values, index, permutation, indices);
    return permutation;
}
