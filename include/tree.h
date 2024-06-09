// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
  struct Node {
    std::vector<Node*> childs;
    char value;
  };

  Node *root = new Node;
  std::vector<std::vector<char>> permuts;
  std::vector<char> Perm;

  void buildTree(Node* node, std::vector<char> value) {
    if (!node) {
      node = new Node;
    }
    if (value.empty()) {
      return;
    }
    for (int i = 0; i < value.size(); ++i) {
      std::vector<char> COPYvalues = value;
      Node* NewRoot = new Node;
      NewRoot->value = COPYvalues[i];
      node->childs.push_back(NewRoot);
      COPYvalues.erase(COPYvalues.begin() + i);
      buildTree(NewRoot, COPYvalues);
    }
  }

  void GeneratePerm(Node* node) {
    if (node == nullptr) {
      return;
    }
    if (node->childs.empty()) {
      char Token = node->value;
      Perm.push_back(Token);
      permuts.push_back(Perm);
      Perm = {};
      return;
    }
      std::cout << node->childs.size() << std::endl;
      for (int i = 0; i < node->childs.size(); ++i) {
        if (node && node->value) {
          char Token = node->value;
          Perm.push_back(Token);
        }
        GeneratePerm(node->childs[i]);
    }
  }

 public:
  explicit Tree(std::vector<char> values) : root(nullptr) {
    root = new Node;
    buildTree(root, values);
    GeneratePerm(root);
  }
  std::vector<char> GetPermute(int i) const {
    if (i < 0 || index >= permuts.size()) {
      return std::vector<char>();
    }
    return permuts[i];
  }
};

#endif  // INCLUDE_TREE_H_
