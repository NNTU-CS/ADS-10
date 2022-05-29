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
  std::vector<std::string> Perm;
  void Permutation(Node* root, std::string s = "") {
    if (!root->leaf.size()) {
      s += root->value;
      Perm.push_back(s);
      return;
    }
  if (root->value != '*') {//корень
    s += root->value;
  }
  for (size_t i = 0; i < root->leaf.size(); ++i) {
    Permutation(root->leaf[i], s);
  }
}
void constructTree(Node* root, std::vector<char> path) {
  if (!path.size()) {
    return;
  }
  if (root->value != '*') {
  for (auto i = path.begin(); i != path.end(); ++i) {
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
    constructTree(root->leaf[i], path);
  }
}

 public:
  std::string operator[](int i) const {
  if (i >= Perm.size()) {
    return "";
  }
  return Perm[i];
}
  explicit Tree(std::vector<char> value) {
  root = new Node;
  root->value = '*';
  constructTree(root, value);
  Permutation(root);
  }
};
#endif  // INCLUDE_TREE_H_
