// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <iostream>
#include <vector>

struct Node {
  char val;
  std::vector<Node *> nodes;
};

class Tree {
 private:
  int size;

 public:
  Node *root;
  void addNode(std::vector<char>, Node *);
  explicit Tree(std::vector<char>);
};

inline Tree::Tree(std::vector<char> vec1) {
  root = new Node;
  addNode(vec1, root);
}

inline void Tree::addNode(std::vector<char> vec1, Node *root) {
  Node *node;
  for (int i = 0; i < vec1.size(); i++) {
    node = new Node;
    node->val = vec1[i];
    root->nodes.push_back(node);
    std::vector<char> newVector = vec1;
    newVector.erase(newVector.begin() + i);
    addNode(newVector, node);
  }
}

#endif  // INCLUDE_TREE_H_
