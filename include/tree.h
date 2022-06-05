// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <iostream>
#include <string>

class Tree {
 private:
  struct Node {
    char val;
    std::vector<Node*> list;
  };

  Node* root;

  void addTree(Node* root, std::vector<char> pathway) {
    if (!pathway.size()) {
      return;
    }
    if (root->val != '*') {
      for (auto i = pathway.begin(); i != pathway.end(); i++) {
        if (*i == root->val) {
          pathway.erase(i);
          break;
        }
      }
    }
    for (size_t i = 0; i < pathway.size(); i++) {
      root->list.push_back(new Node);
    }
    for (size_t i = 0; i < root->list.size(); ++i) {
      root->list[i]->val = pathway[i];
    }
    for (size_t i = 0; i < root->list.size(); ++i) {
      addTree(root->list[i], pathway);
    }
  }

  std::vector<std::string> perm;

  void permut(Node* root, std::string empt = "") {
    if (!root->list.size()) {
      empt += root->val;
      perm.push_back(empt);
    }
    if (root->val != '*') {
      empt += root->val;
    }
    for (size_t i = 0; i < root->list.size(); i++) {
      permut(root->list[i], empt);
    }
  }

 public:
  std::string operator[](int i) const {
    if (i >= perm.size()) {
      return "";
    }
    return perm[i];
  }

  explicit Tree(std::vector<char> val) {
    root = new Node();
    root->val = '*';
    addTree(root, val);
    permut(root);
  }
};

#endif  // INCLUDE_TREE_H_
