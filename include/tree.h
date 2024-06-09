// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

class Node {
 public:
  std::vector<Node*> children;
  char value;
  Node(char val) : value(val) {}
};

class Tree {
 public:
  Node* root;
  Tree(std::vector<char>& elements) {
    root = new Node(' ');
    buildTree(root, elements);
  }
void buildTree(Node* node, std::vector<char> elements) {
  if (elements.empty()) {
    return;
  }
  for (char element : elements) {
    Node* child = new Node(element);
    node->children.push_back(child);
    std::vector<char> remaining;
    for (char e : elements) {
      if (e != element) {
        remaining.push_back(e);
      }
    }
    buildTree(child, remaining);
  }
}
};

void getPermutationFromNode(Node* node, std::string current, int& count, int requiredCount, std::vector<std::string>& permutations) {
  if(node == nullptr) {
    return;
  }
  current.push_back(node->value);
  if(node->children.empty()) {
    count++;
    if(count == requiredCount) {
      permutations.push_back(current);
      return;
    }
  }
  for(auto child : node->children) {
    getPermutationFromNode(child, current, count, requiredCount, permutations);
  }
  current.pop_back();
}

std::vector<char> getPerm(Tree& tree, int requiredCount) {
  std::vector<std::string> permutations;
  int count = 0;
  getPermutationFromNode(tree.root, "", count, requiredCount, permutations);
  if(permutations.empty()) {
    return {};
  }
  std::vector<char> result;
  for(char c : permutations[0]) {
    result.push_back(c);
  }
  return result;
}

#endif  // INCLUDE_TREE_H_
