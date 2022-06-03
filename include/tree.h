// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>

class Tree {
 private:
  struct Node { // ...
    char value;
    std::vector<Node*> child;
  };
  Node* root;
  std::vector<std::string> numbers;

  void createTree(Node* root, std::vector<char> _numbers) {
    if (_numbers.size() == 0)
      return;
    if (root->value != '-') {
      for (auto  i = _numbers.begin(); i != _numbers.end(); ++i) {
        if (*i == root->value) {
          _numbers.erase(i);
          break;
        }
      }
    }
    for (size_t i = 0; i < _numbers.size(); ++i) {
      root->child.push_back(new Node);
    }
    for (size_t i = 0; i < root->child.size(); ++i) {
      root->child[i]->value = _numbers[i];
    }
    for (size_t i = 0; i < root->child.size(); ++i) {
      createTree(root->child[i], _numbers);
    }
  }
  void perm(Node* root, std::string number = "") {
    if (root->value != '-') {
      number += root->value;
    }
    if (!root->child.size()) {
      number += root->value;
      numbers.push_back(number);
      return;
    }
    for (size_t i = 0; i < root->child.size(); ++i) {
      perm(root->child[i], number);
    }
  }

 public:
  std::string operator[](int i) const {
  return numbers[i];
  }
  explicit Tree(std::vector<char> value) {
    root = new Node;
    root->value = '-';
    createTree(root, value);
    perm(root);
  }
};
#endif  // INCLUDE_TREE_H_
