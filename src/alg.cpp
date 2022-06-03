// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> res;
    std::string tmp = tree[n - 1];
    int count = 0;
    while (count < tmp.length()) {
        res.push_back(tmp[count]);
        count++;
    }
  return res;
}
