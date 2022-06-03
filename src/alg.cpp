// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  std::string nach = tree[n - 1];
    std::vector<char> res;
    int i = 0;
    while (i < nach.length()) {
        res.push_back(nach[i]);
        i++;
    }
    return res;
}
