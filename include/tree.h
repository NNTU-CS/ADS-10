// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include<iostream>
#include <vector>

class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> ListOfChild = {};
  };
  std::vector<std::vector<char>> variants = {};
  Node* root;
  void MakeTree(Node* _root, std::vector<char> symbols, int index = -1) {
    if (index != -1)
      symbols.erase(symbols.begin() + index);
    if (!symbols.empty()) {
      for (int i = 0; i < symbols.size(); i++) {
        _root->ListOfChild.push_back(new Node);
        _root->ListOfChild[i]->value = symbols[i];
        MakeTree(_root->ListOfChild[i], symbols, i);
      }
    }
  }
  void Perms(Node* _root, std::vector<char> variables = {}) {
    if (_root->value != '*')
      variables.push_back(_root->value);
    if (_root->ListOfChild.size() == 0) {
      variants.push_back(variables);
    } else {
      for (int i = 0; i < _root->ListOfChild.size(); i++)
        Perms(_root->ListOfChild[i], variables);
    }
  }

 public:
  explicit Tree(std::vector<char> symbols) {
    root = new Node;
    root->value = '*';
    MakeTree(root, symbols);
    }
  std::vector<char> getPerm(int count) {
    Perms(root);
    if (count > variants.size()) {
      std::vector<char> zeroVector = {};
      return zeroVector;
    } else {
      return variants[count - 1];
    }
  }
};
#endif  // INCLUDE_TREE_H_
