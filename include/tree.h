// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>

class Tree {
 private:
  struct Node { // ...
    char value;
    std::vector<Node*> leaf;
  };
  Node* root;
  std::vector<std::string> res;

  void moreTree(Node* root, std::vector<char> path) {
    if (!path.size())
      return;
    if (root->value != '-') {
      for (auto  i = path.begin(); i != path.end(); i++) {
        if (*i == root->value) {
          path.erase(i);
          break;
        }
      }
    }
    for (size_t i = 0; i < path.size(); ++i) {
      root->leaf.push_back(new Node);
    }
    for (size_t i = 0; i < root->leaf.size(); ++i) {
      root->leaf[i]->value = path[i];
    }
    for (size_t i = 0; i < root->leaf.size(); ++i) {
      moreTree(root->leaf[i], path);
    }
  }
  void perm(Node* root, std::string numr = "") {
    if (!root->leaf.size()) {
      numr += root->value;
      res.push_back(numr);
    }
    if (root->value != '*') {
      numr+=root->value;
    }
    for (size_t i = 0; i < root->leaf.size(); i++) {
      perm(root->leaf[i], numr);
    }
  }

 public:
  std::string operator[](int i) const {
    if (i >= res.size()) {
      return "";
    }
    return res[i];
  }
  explicit Tree(std::vector<char> value) {
    root = new Node();
    root->value = '*';
    moreTree(root, value);
    perm(root);
  }
};
#endif  // INCLUDE_TREE_H_
