// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> conseq;
  int a = n;
  std::string go_out = tree[--a];
  int shag = 0;
  if (shag < go_out.size()) {
      while (shag < go_out.length()) {
            conseq.push_back(go_out[shag]);
            shag++;
      }
  }
  return conseq;
}
