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
  Node *root;
  void createTree(Node* root, std::vector<char> cyc) {
    if (!cyc.size())
      return;
    if (root->value != '*') {
      for (auto j = cyc.begin(); j != cyc.end(); j++)
        if (*j == root->value) {
          cyc.erase(j);
          break;
        }
    }
    for (size_t i = 0; i < cyc.size(); i++)
      root->leaf.push_back(new Node());
    for (size_t i = 0; i < root->leaf.size(); i++)
      root->leaf[i]->value = cyc[i];
    for (size_t i = 0; i < root->leaf.size(); i++)
      createTree(root->leaf[i], cyc);
  }
  std::vector<std::string> prm;
  void perm(Node *root, std::string symbol = "") {
    if (!root->leaf.size()) {
      symbol += root->value;
      prm.push_back(symbol);
    }
    if (root->value != '*')
      symbol += root->value;
    for (size_t i = 0; i < root->leaf.size(); i++)
      perm(root->leaf[i], symbol);
  }

 public:
  std::string operator[](int i) const {
    if (i >= prm.size())
      return "";
    return prm[i];
  }
  explicit Tree(std::vector<char> value) {
    root = new Node();
    root->value = '*';
    createTree(root, value);
    perm(root);
  }
};
#endif  // INCLUDE_TREE_H_
