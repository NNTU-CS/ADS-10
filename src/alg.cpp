// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> result;
  const Tree::Node* current = tree.getRoot();

  while (n > 1 && !current->children.empty()) {
    int childCount = current->children.size();
    int permsPerChild = 1;  // Number of permutations per child

    for (int i = 1; i <= childCount; ++i) {
      permsPerChild *= i;
    }

    int childIndex = (n - 1) / permsPerChild;
    result.push_back(current->children[childIndex]->data);

    n = (n - 1) % permsPerChild + 1;
    current = current->children[childIndex];
  }

  return result;
}
