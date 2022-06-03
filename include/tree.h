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
  void createTree(Node* root, std::vector<char> cyc) {
    if (!cyc.size())
      return;
    if (root->value != '*') {
      for (auto k = cyc.begin(); k != cyc.end(); k++)
        if (*k == root->value) {
          cyc.erase(k);
          break;
        }
    }
    for (size_t l = 0; l < cyc.size(); l++)
      root->leaf.push_back(new Node());
    for (size_t l = 0; l < root->leaf.size(); l++)
      root->leaf[l]->value = cyc[l];
    for (size_t l = 0; l < root->leaf.size(); l++)
      createTree(root->leaf[l], cyc);
  }
  std::vector<std::string> prm;
  void perm(Node* root, std::string symbol = "") {
    if (!root->leaf.size()) {
      symbol += root->value;
      prm.push_back(symbol);
    }
    if (root->value != '*')
      symbol += root->value;
    for (size_t l = 0; l < root->leaf.size(); l++)
      perm(root->leaf[l], symbol);
  }

 public:
    std::string operator[](int l) const {
      if (l >= prm.size())
        return "";
      return prm[l];
    }
      explicit Tree(std::vector<char> value) {
      root = new Node();
      root->value = '*';
      createTree(root, value);
      perm(root);
    }
};
#endif  // INCLUDE_TREE_H_
