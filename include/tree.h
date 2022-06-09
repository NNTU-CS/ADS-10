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
  void constructTree(Node* root, std::vector<char> way) {
    if (!way.size())
      return;
    if (root->value != '*') {
      for (auto k = way.begin(); k != way.end(); k++)
        if (*k == root->value) {
          way.erase(k);
          break;
        }
    }
    for (size_t l = 0; l < way.size(); l++)
      root->leaf.push_back(new Node());
    for (size_t l = 0; l < root->leaf.size(); l++)
      root->leaf[l]->value = way[l];
    for (size_t l = 0; l < root->leaf.size(); l++)
      constructTree(root->leaf[l], way);
  }
  std::vector<std::string> prm;
  void Permutation(Node* root, std::string symbol = "") {
    if (!root->leaf.size()) {
      symbol += root->value;
      prm.push_back(symbol);
    }
    if (root->value != '*')
      symbol += root->value;
    for (size_t l = 0; l < root->leaf.size(); l++)
      Permutation(root->leaf[l], symbol);
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
      constructTree(root, value);
      Permutation(root);
    }
};
#endif  // INCLUDE_TREE_H_
