// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string sour = tree[n - 1];
    std::vector<char> tre;
    for (int g = 0; g < sour.length(); g++) {
        tre.push_back(sour[g]);
    }
    return tre;
}
