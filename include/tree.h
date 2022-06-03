// Copyright 2022 Matvey Ryabchikov
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>

class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> children;
  };
  Node* root;
  void create(Node* root, std::vector<char> chars) {
    if (!chars.size()) return;
    if (root->value != '*') {
      for (auto character = chars.begin(); character != chars.end();
           character++)
        if (*character == root->value) {
          chars.erase(character);
          break;
        }
    }
    for (size_t i = 0; i < chars.size(); i++)
      root->children.push_back(new Node());
    for (size_t i = 0; i < root->children.size(); i++)
      root->children[i]->value = chars[i];
    for (size_t i = 0; i < root->children.size(); i++)
      create(root->children[i], chars);
  }
  std::vector<std::string> vec;
  void perm(Node* root, std::string str = "") {
    if (!root->children.size()) {
      str += root->value;
      vec.push_back(str);
    }
    if (root->value != '*') str += root->value;
    for (size_t i = 0; i < root->children.size(); i++)
      perm(root->children[i], str);
  }

 public:
  std::string operator[](int i) const {
    if (i >= vec.size()) return "";
    return vec[i];
  }
  explicit Tree(std::vector<char> value) {
    root = new Node();
    root->value = '*';
    create(root, value);
    perm(root);
  }
};
#endif  // INCLUDE_TREE_H_
