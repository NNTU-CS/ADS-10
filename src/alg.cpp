// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <algorithm>
#include  "tree.h"

Tree::Tree(const std::vector<char>& vec) {
    auto vec_copy = vec;
    std::sort(vec_copy.begin(), vec_copy.end());
    root = createNode(vec_copy, ' ');
}

Tree::Node* Tree::createNode(const std::vector<char>& vec, char data) {
    Node* new_node = new Node;
    new_node->symb = data;
    if (vec.empty()) {
        return new_node;
    }
    new_node->children.reserve(vec.size());
    for (int i = 0; i < vec.size(); ++i) {
        auto vec_copy = vec;
        vec_copy.erase(vec_copy.begin() + i);
        new_node->children.push_back(createNode(vec_copy, vec[i]));
    }
    return new_node;
}

void Tree::deleteNode(Tree::Node* node) {
    for (int i = 0; i < node->children.size(); ++i) {
        deleteNode(node->children[i]);
    }
    delete node;
}

Tree::~Tree() {
    deleteNode(root);
}

void recPerm(Tree::Node* node, int tree_size, int n,
    std::vector<char>* vec) {
    vec->push_back(node->symb);
    if (node->children.empty()) {
        return;
    }
    tree_size /= node->children.size();
    int i = n / tree_size;
    recPerm(node->children[i], tree_size, n - tree_size * i, vec);
}

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  if (tree.root->children.size() == 0 || n == 0) {
        return {};
  }
  --n;
  int tree_size = 1;
  for (int i = 1; i < tree.root->children.size(); ++i) {
      tree_size *= i;
  }
  if (n >= tree_size * tree.root->children.size()) {
      return {};
  }
  int i = n / tree_size;
  std::vector<char> result;
  recPerm(tree.root->children[i], tree_size, n - (tree_size * i), &result);
  return result;
}
