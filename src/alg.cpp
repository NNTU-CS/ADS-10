// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<std::vector<char>> pr = tree.getPerm();
  if (n < 0 || pr.size() < n) {
    return {};
  }
  std::vector<char> temp = pr[n - 1];
  temp.erase(temp.begin());
  return temp;
}
