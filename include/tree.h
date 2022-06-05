// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>
class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> leaf;
  };
  Node* root;

  std::vector<std::string> permut;
  void permutation(Node* root, std::string symb = "") {
    if (!root->leaf.size()) {
      symb += root->value;
      permut.push_back(symb);
    }
    if (root->value != '*') {
      symb += root->value;
    }
    for (size_t i = 0; i < root->leaf.size(); ) {
      permutation(root->leaf[i], symb);
      i++;
    }
  }

  void createTree(Node* root, std::vector<char> path) {
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
    for (size_t i = 0; i < path.size(); ) {
      root->leaf.push_back(new Node);
      i++;
    }
    for (size_t i = 0; i < root->leaf.size(); ) {
      root->leaf[i]->value = path[i];
      ++i;
    }
    for (size_t i = 0; i < root->leaf.size(); ) {
      createTree(root->leaf[i], path);
      ++i;
    }
  }

 public:
  std::string operator[](int j) const {
    if (j >= permut.size()) {
      return "";
    }
    return permut[j];
  }
  explicit Tree(std::vector<char> value) {
    root = new Node;
    root->value = '*';
    createTree(root, value);
    permutation(root);
  }
};
#endif  // INCLUDE_TREE_H_
