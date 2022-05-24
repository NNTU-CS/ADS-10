// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>

class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> sheet;
  };
  Node* root;
  std::vector<std::string> permutation;
  void constructTree(Node* root, std::vector<char> figure) {
    if (!figure.size()) {
      return;
    }
    if (root->value != '*') {
      for (auto x = figure.begin(); x != figure.end(); ++x) {
        if (*x == root->value) {
          figure.erase(x);
          break;
        }
      }
    }
    for (size_t i = 0; i < figure.size(); ++i) {
      root->sheet.push_back(new Node);
    }
    for (size_t i = 0; i < root->sheet.size(); ++i) {
      root->sheet[i]->value = figure[i];
    }
    for (size_t i = 0; i < root->sheet.size(); ++i) {
      constructTree(root->sheet[i], figure);
    }
  }
  void Permutation(Node*root, std::string s = "") {
    if (!root->sheet.size()) {
      s += root->value;
      permutation.push_back(s);
      return;
    }
    if (root->value != '*') {
      s += root->value;
    }
    for (size_t i = 0; i < root->sheet.size(); ++i) {
      Permutation(root->sheet[i], s);
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
