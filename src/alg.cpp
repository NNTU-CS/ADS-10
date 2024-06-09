// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int F(int n) {
  if (n == 0)
    return 1;
  return n * F(n - 1);
}
std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  std::vector<char> res = {};
  if (n < 0 || F(tree.Size()) < n)
    return{};
  res = tree.Got(n - 1);
  res.erase(res.begin());
  return res;
}
