// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int factor(int i) {
  int result = 1;
  for (int j = 1; j <= i; j++) {
    result *= j;
  }
  return result;
}

std::vector<char> getPerm(const Tree &tree, int number) {
  std::vector<char> result;
  if (number <= factor(tree.rot->nodes.size())) {
    Node *rot = tree.rot;
    int i = factor(rot->nodes.size()) / rot->nodes.size();
    for (int j = 0; j < rot->nodes.size(); j++) {
      if ((number <= i * (j + 1)) && (number > j * 2)) {
        rot = rot->nodes[j];
        result.push_back(rot->VL);
      }
    }
    if (number % 2 == 0) {
      rot = rot->nodes[1];
    } else {
      rot = rot->nodes[0];
    }
    result.push_back(rot->VL);
    rot = rot->nodes[0];
    result.push_back(rot->VL);
  }
  return result;
}
