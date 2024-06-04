// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <iostream>
#include <vector>

class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> descendant;
  };

  Node* root = nullptr;
  std::vector<char> perm;
  void CreatePermTree(std::vector<char> elements, Node* node) {
    for (auto element : elements) {
      Node* child = new Node;
      child->value = element;
      node->descendant.push_back(child);
      std::vector<char> remaining = elements;
      remaining.erase(std::remove(remaining.begin(), remaining.end(), element), remaining.end());
      CreatePermTree(remaining, child);
    }
  }
  void GeneratePerm(Node* node) {
    if (node->descendant.empty()) {
      perm.push_back(node->value);
      perms.push_back(perm);
      perm.pop_back();
    }
    for (Node* child : node->descendant) {
      perm.push_back(node->value);
      GeneratePerm(child);
      perm.pop_back();
    }
  }

 public:
  std::vector<std::vector<char>> perms;
  explicit Tree(std::vector<char> elements) {
    root = new Node;
    root->value = 0;
    CreatePermTree(elements, root);
    GeneratePerm(root);
  }
};
#endif  // INCLUDE_TREE_H_
