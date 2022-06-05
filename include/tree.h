// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>
class Tree {
 private:
  struct Node {
  char smthVal;
  std::vector<Node*> greList;
  };
  Node* root;
  void sozdanieTree(Node* root, std::vector<char> per) {
    if (!per.size())
      return;
    if (root->smthVal != '*') {
      for (auto k = per.begin(); k != per.end(); k++)
        if (*k == root->smthVal) {
          per.erase(k);
          break;
        }
    }
    for (size_t i = 0; i < per.size(); i++)
      root->greList.push_back(new Node());
    for (size_t i = 0; i < root->greList.size(); i++)
      root->greList[i]->smthVal = per[i];
    for (size_t i = 0; i < root->greList.size(); i++)
      sozdanieTree(root->greList[i], per);
  }
  std::vector<std::string> permutation;
  void prm(Node* root, std::string symbol = "") {
    if (!root->greList.size()) {
      symbol += root->smthVal;
      permutation.push_back(symbol);
    }
    if (root->smthVal != '*')
      symbol += root->smthVal;
    for (size_t i = 0; i < root->greList.size(); i++)
      prm(root->greList[i], symbol);
  }


 public:
    std::string operator[](int i) const {
      if (i >= permutation.size())
        return "";
      return permutation[i];
    }
      explicit Tree(std::vector<char> smthVal) {
      root = new Node();
      root->smthVal = '*';
      sozdanieTree(root, smthVal);
      prm(root);
    }
};
#endif  // INCLUDE_TREE_H_
