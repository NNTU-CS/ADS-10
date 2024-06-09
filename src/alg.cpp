// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

Tree::Tree(const std::vector<char>& in) {
  buildTree(in);
}

void Tree::buildTree(const std::vector<char>& in) {
  if (in.empty()) {
    return;
  }
  std::vector<char> left(in.begin() + 1, in.end());
  std::vector<char> right(in.begin() + 1, in.end());
  buildTree(left);
  buildTree(right);
}

std::vector<char> getPerm(const Tree& tree, int n) {
  if (n < 1) {
    return {};
  }
  return tree.getPermRecursive(n, 0);
}

std::vector<char> Tree::getPermRecursive(int n, int level) {
  if (n > 1) {
    std::vector<char> left = getPermRecursive(n - 1, level + 1);
    std::vector<char> right = getPermRecursive(n - 1, level + 1);
    std::vector<char> result;
    for (char c : left) {
      for (char d : right) {
        result.push_back(c);
        result.push_back(d);
      }
    }
    return result;
  } else {
    return {};
  }
}
