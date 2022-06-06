
// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string nachalo = tree[n - 1];
    std::vector<char> itog;
    int a = 0;
    while (a < nachalo.length()) {
        itog.push_back(nachalo[a]);
        a++;
    }
    return itog;
}
