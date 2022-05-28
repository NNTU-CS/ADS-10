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

  void buildTree(Node* root, std::vector<char> cycle) {
    if (!cycle.size())
      return;
    if (root->value != '*') {
      for (auto i = cycle.begin(); i != cycle.end(); i++)
        if (*i == root->value) {
          cycle.erase(i);
          break;
        }
    }
    for (size_t i = 0; i < cycle.size(); i++)
      root->leaf.push_back(new Node());
    for (size_t i = 0; i < root->leaf.size(); i++)
      root->leaf[i]->value = cycle[i];
    for (size_t i = 0; i < root->leaf.size(); i++)
      buildTree(root->leaf[i], cycle);
  }

  std::vector<std::string> prm;
  void permutation(Node* root, std::string symb = "") {
    if (!root->leaf.size()) {
      symb += root->value;
      prm.push_back(symb);
    }
    if (root->value != '*')
      symb += root->value;
    for (size_t i = 0; i < root->leaf.size(); i++)
      permutation(root->leaf[i], symb);
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
      buildTree(root, value);
      permutation(root);
    }
};

#endif  // INCLUDE_TREE_H_
