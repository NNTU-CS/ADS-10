// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
  bool is_root = false;
  char value;
  std::vector<Node*> children;
};

class Tree {
 private:
  Node* root;
  std::vector<std::vector<char>> permutations;

  void buildTree(Node* node, const std::vector<char>& elements) {
    for (char elem : elements) {
      Node* child = new Node;
      child->value = elem;
      node->children.push_back(child);
      std::vector<char> remaining_elements(elements);
      remaining_elements.erase(std::remove(remaining_elements.begin(),
                                           remaining_elements.end(), elem),
                               remaining_elements.end());
      buildTree(child, remaining_elements);
    }
  }

  void generatePermutations(Node* node, std::vector<char> current_permutation) {
    if (!node->is_root) {
      current_permutation.push_back(node->value);
    }
    if (node->children.empty()) {
      permutations.push_back(current_permutation);
    }
    for (Node* child : node->children) {
      generatePermutations(child, current_permutation);
    }
  }

 public:
  explicit Tree(const std::vector<char>& elements) {
    root = new Node;
    root->is_root = true;
    buildTree(root, elements);
    std::vector<char> current;
    generatePermutations(root, current);
  }

  ~Tree() { deleteTree(root); }

  void deleteTree(Node* node) {
    for (Node* child : node->children) {
      deleteTree(child);
    }
    delete node;
  }

  std::vector<std::vector<char>> getPermutations() const {
    return permutations;
  }
};

#endif  // INCLUDE_TREE_H_
