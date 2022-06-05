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

  std::vector<std::string> perm;
  void permutation(Node* root, std::string sym = "") {
    if (!root->leaf.size()) {
      sym += root->value;
      perm.push_back(sym);
    }
    if (root->value != '*') {
      sym += root->value;
    }
    for (size_t a = 0; a < root->leaf.size(); a++) {
      permutation(root->leaf[a], sym);
    }
  }

  void buildTree(Node* root, std::vector<char> path) {
    if (!path.size()) {
      return;
    }
    if (root->value != '*') {
      for (auto a = path.begin(); a != path.end(); a++) {
        if (*a == root->value) {
          path.erase(a);
          break;
        }
      }
    }
    for (size_t a = 0; a < path.size(); a++) {
      root->leaf.push_back(new Node);
    }
    for (size_t a = 0; a < root->leaf.size(); ++a) {
      root->leaf[a]->value = path[a];
    }
    for (size_t a = 0; a < root->leaf.size(); ++a) {
      buildTree(root->leaf[a], path);
    }
  }

 public:
  std::string operator[](int a) const {
    if (a >= perm.size()) {
      return "";
    }
    return perm[a];
  }
  explicit Tree(std::vector<char> value) {
    root = new Node();
    root->value = '*';
    buildTree(root, value);
    permutation(root);
  }
};




#endif  // INCLUDE_TREE_H_
