// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string start = tree[n - 1];
    std::vector<char> res;
    int a = 0;
    while (a < start.length()) {
        res.push_back(start[a]);
        a++;
    }
    return res;
}
