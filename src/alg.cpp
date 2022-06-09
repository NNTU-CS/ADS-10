// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  std::string restree = tree[n - 1];
  std::vector<char> perms;
  int i = 0;
  while (i < restree.length()) {
      perms.push_back(restree[i]);
      i++;
    }
  return perms;
}
