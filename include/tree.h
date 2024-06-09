// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
  bool root = false;
  char value;
  std::vector<Node*> permutations;
};

class Tree {
 private:
  Node* _root;
  std::vector<std::vector<char> > perm;

  void append(Node* root, const std::vector<char>& vecperm) {
    for (char c : vecperm) {
      Node* temp = new Node;
      temp->value = c;
      root->permutations.push_back(temp);
      std::vector<char> remainingChars(vecperm);
      remainingChars.erase(std::find(remainingChars.begin(),
        remainingChars.end(), c));
      append(temp, remainingChars);
    }
  }

  void findP(Node* root, std::vector<char> vecperm) {
    if (!root->root) vecperm.push_back(root->value);
    if (root->permutations.empty()) perm.push_back(vecperm);
    for (Node* child : root->permutations) findP(child, vecperm);
  }

 public:
  explicit Tree(const std::vector<char>& Vector) {
    _root = new Node;
    _root->root = true;
    append(_root, Vector);
    std::vector<char> current;
    findP(_root, current);
  }

  std::vector<std::vector<char> > getPermutations() const {
    return perm;
  }
};
#endif  // INCLUDE_TREE_H_
