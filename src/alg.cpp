// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> result = {};
    if (n < 0 || factorial(tree.GetSize()) < n)
      return {};
    result = tree.GetPerm(n-1);
    result.erase(result.begin());
    return result;
}
