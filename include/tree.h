// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> potomki;
  };
  Node *root;
  std::vector<std::vector<char>> vecPermutations;

  void treeBuild(Node *root, std::vector<char> initValues) {
    int vecSize = initValues.size();
    for (int i = 0; i < vecSize; i++) {
      Node *potomok = new Node; 
      std::vector<char> leftValues = initValues;
      int lastElement = leftValues.begin() + i;
      potomok->value = initValues[i];
      root->potomki.emplace_back(potomok);
      leftValues.erase(lastElement);
      treeBuild(potomok, leftValues);
    }
  }
};
#endif  // INCLUDE_TREE_H_
