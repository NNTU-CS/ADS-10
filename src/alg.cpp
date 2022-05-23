// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string s = tree[n-1];
  std::vector<char> perm;
  for (int i = 0; i < s.length(); ++i) {
    perm.push_back(s[i]);
  }
  return perm;
}
