// Copyright 2022 NNTU-CS
//Made by AndySter
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string start = tree[n-1];
  std::vector<char> resultat;
  int count = 0;
  while (count < start.length()) {
    resultat.push_back(start[count]);
    count++;
  }
  return resultat;
}
