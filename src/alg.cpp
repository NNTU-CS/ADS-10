// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

unsigned long long factorial(unsigned long long i) {
  unsigned long long result = 1;
  for (unsigned long long j = 1; j <= i; j++) {
    result *= j;
  }
  return result;
}

std::vector<char> getPerm(const Tree &tree, int num) {
  std::vector<char> result;
  if (num <= factorial(tree.root->nodes.size())) {
    Node *root = tree.root;
    long long i = factorial(root->nodes.size()) / root->nodes.size();
    for (int j = 0; j < root->nodes.size(); j++) {
      if ((num <= i * (j + 1)) && (num > j * 2)) {
        root = root->nodes[j];
        result.push_back(root->val);
      }
    }
    if (num % 2 == 0) {
      root = root->nodes[1];
    } else {
      root = root->nodes[0];
    }
    result.push_back(root->val);
    root = root->nodes[0];
    result.push_back(root->val);
  }
  return result;
}

