// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> ret_per;
    int s = tree.per_size;
    int f = tree.n_fact;
    if ((n <= f) && (n > 0)) {
        n = (n - 1) * s;
        for (int i = 0; i < s; i++) {
            ret_per.push_back(tree.data[n + i]);
        }
    }
    return ret_per;
}
