// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <vector>

class Tree {
 public:
  struct Node {
    char data;
    std::vector<Node> children;

    explicit Node(char value) : data(value) {}
  };

 private:
  Node root = Node(' ');
  size_t length = 0;

 public:
  void buildTree(Node* node, const std::vector<char>& remaining) {
    if (remaining.empty()) return;

    for (char c : remaining) {
      node->children.emplace_back(c);

      std::vector<char> newRemaining = remaining;
      newRemaining.erase(
          std::remove(newRemaining.begin(), newRemaining.end(), c),
          newRemaining.end());

      buildTree(&node.children.back(), newRemaining);
    }
  }

  explicit Tree(const std::vector<char>& elements) {
    length = elements.size();
    buildTree(&root, elements);
  }

  const Node& getRoot() const { return root; }
  size_t getLength() const { return length; }
};

#endif  // INCLUDE_TREE_H_
