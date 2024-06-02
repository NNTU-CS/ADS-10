// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cstdlib>
#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  size_t len = tree.getLength();
  std::vector<uint64_t> factorials(tree.getLength() + 1, 1);
  for (size_t i = 1; i < factorials.size(); ++i) {
    factorials[i] = factorials[i - 1] * i;
  }

  size_t high = len;
  std::vector<char> result;
  const Tree::Node* current = &tree.getRoot();

  while (high > 0) {
    if (factorials[high] < n) {
      return {};
    }
    for (const Tree::Node& child : current->children) {
      if (factorials[high - 1] < n) {
        n -= factorials[high - 1];
        continue;
      }
      --high;
      result.push_back(child.data);
      current = &child;
      break;
    }
  }

  return result;
}
