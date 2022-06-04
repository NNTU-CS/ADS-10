// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
      char value;
      std::vector<Node*> vetk;
    };
  Node* root;
  std::vector<std::string> perm;

  void Perm(Node* root, std::string str = "") {
    if (!root->vetk.size()) {
      str += root->value;
      perm.push_back(str);
    }
    if (root->value != '*') {
      str += root->value;
    }
    for (int i = 0; i < root->vetk.size(); i++) {
      Perm(root->vetk[i], str);
    }
  }

  void makeTree(Node* root, std::vector<char> vecto) {
    if (!vecto.size()) {
      return;
    }
    if (root->value != '*') {
      vecto.erase(std::find(vecto.begin(), vecto.end(), root->value));
    }
    for (int i = 0; i < vecto.size(); i++) {
      root->vetk.push_back(new Node());
    }
    for (int i = 0; i < root->vetk.size(); i++) {
      root->vetk[i]->value = vecto[i];
      makeTree(root->vetk[i], vecto);
    }
  }

 public:
    explicit Tree(std::vector<char> vecto) {
      root = new Node();
      root->value = '*';
      makeTree(root, vecto);
      Perm(root);
    }

    std::string get(int i) const {
      if (i >= perm.size()) {
        return "";
      }
      return perm[i];
    }
};
#endif  // INCLUDE_TREE_H_
