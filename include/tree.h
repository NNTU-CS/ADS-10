// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include  <vector>
#include  <string>
#include <iostream>

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
      for (auto c = pathway.begin(); c != pathway.end(); c++) {
        if (*c == root->val) {
          pathway.erase(c);
          break;
        }
      }
    }
    for (size_t c = 0; c < pathway.size(); c++) {
      root->list.push_back(new Node);
    }
    for (size_t c = 0; c < root->list.size(); ++c) {
      root->list[c]->val = pathway[c];
    }
    for (size_t c = 0; c < root->list.size(); ++c) {
      addTree(root->list[c], pathway);
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
    for (size_t c = 0; c < root->list.size(); c++) {
      permut(root->list[c], empt);
    }
  }

 public:
  std::string operator[](int c) const {
    if (c >= perm.size()) {
      return "";
    }
    return perm[c];
  }

  explicit Tree(std::vector<char> val) {
    root = new Node();
    root->val = '*';
    addTree(root, val);
    permut(root);
  }
};
#endif  // INCLUDE_TREE_H_
