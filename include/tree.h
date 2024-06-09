// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
  bool root = false;
  char val;
  std::vector<Node*> permutations;
};

class Tree {
 private:
  Node* mm_root;
  std::vector<std::vector<char> > permut;
  void append(Node* root, const std::vector<char>& vect_perm) {
    for (char c : vect_perm) {
      Node* temp = new Node;
      temp->val = c;
      root->permutations.push_back(temp);
      std::vector<char> remainingChars(vect_perm);
      remainingChars.erase(std::find(remainingChars.begin(), remainingChars.end(), c));
      append(temp, remainingChars);
    }
  }
  void findP(Node* root, std::vector<char> vect_perm) {
    if (!root->root) {
        vect_perm.push_back(root->val);
    }
    if (root->permutations.empty()) {
        permut.push_back(vect_perm);
    }
    for (auto child : root->permutations) {
        findP(child, vect_perm);
    }
  }

 public:
  explicit Tree(const std::vector<char>& Vector) {
    mm_root = new Node;
    mm_root->root = true;
    append(mm_root, Vector);
    std::vector<char> current;
    findP(mm_root, current);
  }
  std::vector<std::vector<char> > getPermutations() const {
    return permut;
  }
};
#endif  // INCLUDE_TREE_H_
