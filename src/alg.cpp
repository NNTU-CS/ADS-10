// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string str = tree[n - 1];
    std::vector<char> ch;
    for (int i = 0; i < str.length(); i++) {
        ch.push_back(str[i]);
    }
    return ch;
}
