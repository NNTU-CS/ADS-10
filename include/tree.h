// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>
class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> pack;
  };
  Node* root;
  std::vector<std::string> permutation;
  void constructTree(Node* root, std::vector<char> form) {
    if (!form.size()) {
      return;
    }
    if (root->value != '*') {
      for (auto j = form.begin(); j != form.end(); ++j) {
        if (*j == root->value) {
          form.erase(j);
          break;
        }
      }
    }
    for (size_t i = 0; i < form.size(); ++i) {
      root->pack.push_back(new Node);
    }
    for (size_t i = 0; i < root->pack.size(); ++i) {
      root->pack[i]->value = form[i];
    }
    for (size_t i = 0; i < root->pack.size(); ++i) {
      constructTree(root->pack[i], form);
    }
  }
  void Permutation(Node*root, std::string s = "") {
    if (!root->pack.size()) {
      s += root->value;
      permutation.push_back(s);
      return;
    }
    if (root->value != '*') {
      s += root->value;
    }
    for (size_t i = 0; i < root->pack.size(); ++i) {
      Permutation(root->pack[i], s);
    }
  }

 public:
  explicit Tree(std::vector<char> v) {
    root = new Node;
    root->value = '*';
    constructTree(root, v);
    Permutation(root);
  }
  std::string operator[](int i) const {
    if (i >= permutation.size()) {
      return "";
    }
    return permutation[i];
  }
};
#endif  // INCLUDE_TREE_H_
