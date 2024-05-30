// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <vector>
#include  "tree.h"
using namespace std;
int fact(int n) {
    if (n == 1) return 1;
    return n * fact(n - 1);
}

int getChildIndex(int index, int numCh) {
    int chIndex = index / numCh;
    index -= chIndex * numCh;
    return chIndex;
}

void getPermHelper(vector<char>& values, int index, vector<char>& perm, vector<int>& idx) {
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

    vector<char> chValues;
    for (int i = 0; i < values.size(); ++i) {
        if (i != idx.back()) {
            chValues.push_back(values[i]);
        }
    }
    getPermHelper(chValues, index, perm, idx);
    perm.push_back(values[idx.back()]);
    idx.pop_back();
}

vector<char> getPerm(const Tree& values, int index) {
    if (index < 0 || index >= fact(values.size())) {
        throw "Invalid index";
    }

    vector<char> permutation;
    vector<int> indices;
    getPermHelper(values, index, permutation, indices);
    return permutation;
}
