// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  return tree.getPermutation(n);
}

Tree::Tree(const std::vector<char>& elements) {
  if (!elements.empty()) {
    root = std::make_shared<Node>(elements[0]);
    std::vector<char> remaining_elements(elements.begin() + 1, elements.end());
    buildTree(root, remaining_elements);
  }
}

void Tree::buildTree(std::shared_ptr<Node> node, std::vector<char> elements) {
  if (elements.empty()) {
    return;
  }

  for (char el : elements) {
    auto child = std::make_shared<Node>(el);
    node->children.push_back(child);

    std::vector<char> remaining_elements;
    for (char e : elements) {
      if (e != el) {
        remaining_elements.push_back(e);
      }
    }

    buildTree(child, remaining_elements);
  }
}

std::vector<char> Tree::getPermutation(int n) const {
  std::vector<char> result;
  if (!root) return result;

  int count = 0;
  std::vector<char> path;
  getPermutationRecursive(root, path, count, n, result);

  return result;
}

void Tree::getPermutationRecursive(std::shared_ptr<Node> node,
                                   std::vector<char>& path, int& count,
                                   int target,
                                   std::vector<char>& result) const {
  path.push_back(node->value);

  if (node->children.empty()) {
    count++;
    if (count == target) {
      result = path;
    }
  } else {
    for (const auto& child : node->children) {
      getPermutationRecursive(child, path, count, target, result);
      if (!result.empty()) {
        break;
      }
    }
  }

  path.pop_back();
}
