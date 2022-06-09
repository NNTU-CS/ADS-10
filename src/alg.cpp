// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> change;
  std::string perestan = tree.getChange(n);
  for (int i = 0; i < perestan.length(); ++i) {
    change.push_back(perestan[i]);
  }
  return change;
}
