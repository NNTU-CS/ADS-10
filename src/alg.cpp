// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> result;
  if (n > tree.perms.size()) {
    result.push_back('1');
    result.clear();
  } else {
    result = tree.perms[n - 1];
    reverse(result.begin(), result.end());
    result.pop_back();
    reverse(result.begin(), result.end());
  }
  return result;
}
