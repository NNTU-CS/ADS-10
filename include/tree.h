// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>
class Tree {
 private:
  struct Node {
    char val;
    std::vector<Node*> child;
  };
  Node* root;
  std::vector<std::string> nums;
  void createTree(Node* root, std::vector<char> _nums) {
    if (_nums.size() == 0)
      return;
    if (root->val != '-') {
      for (auto  i = _nums.begin(); i != _nums.end(); ++i) {
        if (*i == root->val) {
          _nums.erase(i);
          break;
        }
      }
    }
    for (size_t i = 0; i < _nums.size(); ++i) {
      root->child.push_back(new Node);
    }
    for (size_t i = 0; i < root->child.size(); ++i) {
      root->child[i]->val = _nums[i];
    }
    for (size_t i = 0; i < root->child.size(); ++i) {
      createTree(root->child[i], _nums);
    }
  }
  void perm(Node* root, std::string num = "") {
    if (root->val != '-') {
      num += root->val;
    }
    if (!root->child.size()) {
      num += root->val;
      nums.push_back(num);
      return;
    }
    for (size_t i = 0; i < root->child.size(); ++i) {
      perm(root->child[i], num);
    }
  }

 public:
  std::string operator[](int i) const {
  return nums[i];
  }
  explicit Tree(std::vector<char> val) {
    root = new Node;
    root->val = '-';
    createTree(root, val);
    perm(root);
  }
};
#endif  // INCLUDE_TREE_H_
