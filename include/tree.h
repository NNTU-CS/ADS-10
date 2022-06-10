// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>

class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> sheet;
  };
  Node* root;
  std::vector<std::string> perest;
  void constructTree(Node* root, std::vector<char> path) {
    if (!path.size()) {
      return;
    }
    if (root->value != '*') {
      for (auto i = path.begin(); i != path.end(); ++i) {
        if (*i == root->value) {
          path.erase(i);
          break;
        }
      }
    }
    for (size_t i = 0; i < path.size(); ++i) {
      root->sheet.push_back(new Node);
    }
    for (size_t i = 0; i < root->sheet.size(); ++i) {
      root->sheet[i]->value = path[i];
    }
    for (size_t i = 0; i < root->sheet.size(); ++i) {
      constructTree(root->sheet[i], path);
    }
  }
  void Perestanovka(Node* root, std::string f = "") {
    if (!root->sheet.size()) {
      f += root->value;
      perest.push_back(f);
      return;
    }
    if (root->value != '*') {
      f += root->value;
    }
    for (size_t i = 0; i < root->sheet.size(); ++i) {
      Perestanovka(root->sheet[i], f);
    }
  }

 public:
  std::string operator[](int i) const {
    if (i >= perest.size()) {
      return "";
    }
    return perest[i];
  }
  explicit Tree(std::vector<char> value) {
    root = new Node;
    root->value = '*';
    constructTree(root, value);
    Perestanovka(root);
  }
};

#endif  // INCLUDE_TREE_H_
