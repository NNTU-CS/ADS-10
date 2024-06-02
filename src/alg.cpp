// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <vector>
#include  "tree.h"

int Factorial(int n) {
    int f = 1;
    if ((n == 0) || (n == 1)) {
        f = 1;
    } else {
        for (int i = 1; i <= n; i++)
            f *= i;
    }
    return f;
}

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> res;
    Tree tr = tree;
    int depth = tr.depthTree();
    int predel = 1;
    int d = depth - 1;
    int newn = n - 1;
    for (int i = depth; i > 0; i--) {
        predel = predel * i;
    }
    if (n <= predel) {
        Node* tmp = tree.root;
        while (d >= 0) {
            tmp = tmp->Leaves[newn / Factorial(d)];
            res.push_back(tmp->value);
            newn = newn - newn / Factorial(d) * Factorial(d);
            d--;
        }
        return res;
    }
    return {};
}
