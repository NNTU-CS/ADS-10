// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string start = tree[n - 1];
    std::vector<char> result;
    int i = 0;
    while (i < start.length()) {
        result.push_back(start[i]);
        i++;
    }
    return result;
  // напишите реализацию
}
