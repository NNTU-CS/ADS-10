// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
using std::vector;
vector<char> getPerm(const Tree& tree, int n) {
  vector<char> res;
    for (int i = 0; i < tree[n - 1].length(); i++) {
        res.push_back(tree[n - 1][i]);
    }
    return res;
}
