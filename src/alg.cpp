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

int getChildIndex(int index, int numCh) {
    int chIndex = index / numCh;
    index -= chIndex * numCh;
    return chIndex;
}

void getPermHelper(const std::vector<char>& val, int in, const std::vector<char>& p, const std::vector<int>& idx) {
    if (val.empty()) {
        return;
    }

    int numChildren = fact(val.size() - 1);
    if (numChildren == 0) {
        p.push_back(val[0]);
        return;
    }

    int chIndex = getChildIndex(in, numChildren);
    idx.push_back(chIndex);
    in -= chIndex * numChildren;

    std::vector<char> chValues;
    for (int i = 0; i < val.size(); ++i) {
        if (i != idx.back()) {
            chValues.push_back(val[i]);
        }
    }
    getPermHelper(chValues, in, p, idx);
    p.push_back(val[idx.back()]);
    idx.pop_back();
}

std::vector<char> getPerm(const Tree& values, int index) {
    if (index < 0 || index >= fact(values.size())) {
        throw "Invalid index";
    }

    std::vector<char> permutation;
    std::vector<int> indices;
    getPermHelper(values, index, permutation, indices);
    return permutation;
}
