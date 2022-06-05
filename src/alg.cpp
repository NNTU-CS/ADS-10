// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string s = tree[n - 1];
    std::vector<char> der;
    for (int k = 0; k < s.length();) {
        der.push_back(s[k]);
        k++;
    }
    return der;
}
