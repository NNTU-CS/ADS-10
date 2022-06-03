// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>

class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> child;
  };
  Node* root;
  std::vector<std::string> list;
  void CreateNewTree(Node* root, std::vector<char> _list) {
    if (!_list.size()) {
      return;
    }
    if (root->value != '*') {
      size_t j = 0;
      for (auto i = _list.begin(); i != _list.end(); i++) {
        j++;
        if (*i == root->value) {
          _list.erase(i);
          break;
        } else {
          j--;
        }
      }
    }
    for (size_t i = 0; i < _list.size(); ++i) {
      root->child.push_back(new Node);
    }
    for (size_t i = 0; i < root->child.size(); ++i) {
      root->child[i]->value = _list[i];
    }
    for (size_t i = 0; i < root->child.size(); ++i) {
      CreateNewTree(root->child[i], _list);
    }
  }
  void Permut(Node* root, std::string s = "") {
    if (!root->child.size()) {
      s += root->value;
      list.push_back(s);
      return;
    }
    if (root->value != '*') {
      s += root->value;
    }
    for (size_t i = 0; i < root->child.size(); i++) {
      Permut(root->child[i], s);
    }
  }

 public:
  std::string operator[](int i) const {
    return list[i];
  }
  explicit Tree(std::vector<char> value) {
    root = new Node;
    root->value = '*';
    CreateNewTree(root, value);
    Permut(root);
  }
};
#endif  // INCLUDE_TREE_H_
