// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <iostream>
#include <vector>

struct Node {
  char VL;
  std::vector<Node *> nodes;
};

class Tree {
 private:
  int size;

 public:
  Node *rot;
  void addNode(std::vector<char>, Node *);
  explicit Tree(std::vector<char>);
};

inline Tree::Tree(std::vector<char> vector1) {
  addNode(vector1, new Node);
}

inline void Tree::addNode(std::vector<char> vector1, Node *rot) {
  Node *node;
  for (int i = 0; i < vector1.size(); i++) {
    node = new Node;
    node->VL = vector1[i];
    rot->nodes.push_back(node);
    std::vector<char> newVector = vector1;
    newVector.erase(newVector.begin() + i);
    addNode(newVector, node);
  }
}

#endif  // INCLUDE_TREE_H_
