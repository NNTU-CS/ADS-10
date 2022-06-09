// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>

class Tree {
 private:
  struct Node { // ...
    char value;
    std::vector<Node*> chd;
  };
  Node* root;
  std::vector<std::string> numbers;

  void createTree(Node* root, std::vector<char> _numbers) {
    if (_numbers.size() == 0)
      return;
    if (root->value != '-') {
      for (auto i = _numbers.begin(); i != _numbers.end(); ++i) {
        if (*i == root->value) {
          _numbers.erase(i);
          break;
        }
      }
    }
    for (size_t i = 0; i < _numbers.size(); ++i) {
      root->chd.push_back(new Node);
    }
    for (size_t i = 0; i < root->chd.size(); ++i) {
      root->chd[i]->value = _numbers[i];
    }
    for (size_t i = 0; i < root->chd.size(); ++i) {
      createTree(root->chd[i], _numbers);
    }
  }
  void perem(Node* root, std::string number = "") {
    if (root->value != '-') {
      number += root->value;
    }
    if (!root->chd.size()) {
      number += root->value;
      numbers.push_back(number);
      return;
    }
    for (size_t i = 0; i < root->chd.size(); ++i) {
      perem(root->chd[i], number);
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
    perem(root);
  }
};
#endif  // INCLUDE_TREE_H_
