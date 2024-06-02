// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <vector>

class Tree {
 private:
  struct Node {
    char data;
    std::vector<Node*> children;

    explicit Node(char value) : data(value) {}
  };

  Node* root;

  void buildTree(Node* node, const std::vector<char>& remaining) {
    if (remaining.empty()) return;

    for (char c : remaining) {
      Node* child = new Node(c);
      node->children.push_back(child);

      std::vector<char> newRemaining = remaining;
      newRemaining.erase(
          std::remove(newRemaining.begin(), newRemaining.end(), c),
          newRemaining.end());

      buildTree(child, newRemaining);
    }
  }

 public:
  explicit Tree(const std::vector<char>& elements) {
    root = new Node(' ');
    buildTree(root, elements);
  }

  const Node* getRoot() const { return root; }
};

#endif  // INCLUDE_TREE_H_
