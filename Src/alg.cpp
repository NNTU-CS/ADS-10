// Copyright 2022 NNTU-CS

#include  <iostream>

#include  <fstream>

#include  <locale>

#include  <cstdlib>

#include  <vector>

#include  "tree.h"



std::vector<char> getPerm(const Tree& tree, int n) {

  std::vector<char> res;

  std::string permutation = tree.get(n-1);



  for (int i = 0; i < permutation.size(); i++) {

    res.push_back(permutation[i]);

  }

  return res;

}
