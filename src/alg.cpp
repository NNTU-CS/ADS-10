// Copyright 2022 Matvey Ryabchikov
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>

#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> result;
  for (int i = 0; i < tree[n - 1].length(); i++)
    result.push_back(tree[n - 1][i]);
  return result;
}
