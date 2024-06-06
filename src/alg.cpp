// Copyright 2022 NNTU-CS
#include  "tree.h"


int fact(int i) {
    int res = 1;
    for (int j = 1; j <= i; j++) {
        res *= j;
    }
    return res;
}

std::vector<char> getPerm(const Tree &tree, int n) {
    std::vector<char> vector;
    if (n < fact(tree.root->vecChild.size())) {
        auto root = tree.root;
        int i = fact(root->vecChild.size()) / root->vecChild.size();
        for (int j = 0; j < root->vecChild.size(); j++) {
            if (n > j * 2 && n <= i * (j + 1)) {
                root = root->vecChild[j];
                vector.push_back(root->value);
            }
        }
        if (n % 2 == 1) {
            root = root->vecChild[0];
            vector.push_back(root->value);
        } else {
            root = root->vecChild[1];
            vector.push_back(root->value);
        }
        root = root->vecChild[0];
        vector.push_back(root->value);
    }
    return vector;
}
