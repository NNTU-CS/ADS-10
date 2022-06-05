// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>

class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> list;
  };
  Node* root;
  std::vector<std::string> der;

  void mnogTree(Node* root, std::vector<char> pyt) {
    if (!pyt.size())
      return;
    if (root->value != '-') {
      for (auto  i = pyt.begin(); i != pyt.end(); i++) {
        if (*i == root->value) {
          pyt.erase(i);
          break;
        }
      }
    }
    for (size_t i = 0; i < pyt.size(); ++i) {
      root->list.push_back(new Node);
    }
    for (size_t i = 0; i < root->list.size(); ++i) {
      root->list[i]->value = pyt[i];
    }
    for (size_t i = 0; i < root->list.size(); ++i) {
      mnogTree(root->list[i], pyt);
    }
  }
  void perm(Node* root, std::string numr = "") {
    if (!root->list.size()) {
      numr += root->value;
      der.push_back(numr);
    }
    if (root->value != '*') {
      numr+=root->value;
    }
    for (size_t i = 0; i < root->list.size(); i++) {
      perm(root->list[i], numr);
    }
  }

 public:
  std::string operator[](int i) const {
    if (i >= der.size()) {
      return "";
    }
    return der[i];
  }
  explicit Tree(std::vector<char> value) {
    root = new Node();
    root->value = '*';
    mnogTree(root, value);
    perm(root);
  }
};
#endif  // INCLUDE_TREE_H_
