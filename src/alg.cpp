// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int fact(int i) {
    int res = 1;
    for (int j = 1; j <= i; j++) {
        res *= j;
    }
    return res;
}

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> vector;
    if (n <= fact(tree.root->vecChilds.size())) {
        auto root = tree.root;
        int i = fact(root->vecChilds.size()) / root->vecChilds.size();
        for (int j = 0; j < root->vecChilds.size(); j++) {
            if (n > j * 2 && n <= i * (j + 1)) {
                root = root->vecChilds[j];
                vector.push_back(root->val);
            }
        }
        if (n % 2 == 1) {
            root = root->vecChilds[0];
            vector.push_back(root->val);
        } else {
            root = root->vecChilds[1];
            vector.push_back(root->val);
        }
        root = root->vecChilds[0];
        vector.push_back(root->val);
    }
    return vector;
}
