// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> leaf;
  };
  Node* root;
  void buildTree(Node* root, std::vector<char> path) {
    if (!path.size()) {
      return;
    }
    if (root->value != '*') {
      for (auto i = path.begin(); i != path.end(); i++) {
        if (*i == root->value) {
          path.erase(i);
          break;
        }
      }
    }
    for (size_t i = 0; i < path.size(); i++) {
      root->leaf.push_back(new Node);
    }
    for (size_t i = 0; i < root->leaf.size(); ++i) {
      root->leaf[i]->value = path[i];
    }
    for (size_t i = 0; i < root->leaf.size(); ++i) {
      buildTree(root->leaf[i], path);
    }
  }
  std::vector<std::string> perm;
  void permutation(Node* root, std::string sym = "") {
    if (!root->leaf.size()) {
      sym += root->value;
      perm.push_back(sym);
    }
    if (root->value != '*') {
      sym += root->value;
    }
    for (size_t i = 0; i < root->leaf.size(); i++) {
      permutation(root->leaf[i], sym);
    }
  }

 public:
  std::string operator[](int i) const {
    if (i >= perm.size()) {
      return "";
    }
    return perm[i];
  }
  explicit Tree(std::vector<char> value) {
    root = new Node();
    root->value = '*';
    buildTree(root, value);
    permutation(root);
  }
};
#endif  // INCLUDE_TREE_H_
