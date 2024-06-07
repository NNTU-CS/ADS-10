// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Tree {
 private:
  struct Node {
    char ch;
    std::vector<Node*> children;
    Node() : ch('#') {}
  };
  Node* root = nullptr;
  std::vector<std::vector<char>> permutations;
  void createTree(Node*, const std::vector<char>&);
  void makePermutations(Node*, std::vector<char>);
  void createTreePermutations(const std::vector<char>&);
 public:
  explicit Tree(const std::vector<char>&);
  std::vector<std::vector<char>> getPermutations() const;
};

void Tree::createTree(Node* root, const std::vector<char>& order) {
  if (root != nullptr) {
    for (const auto& symb : order) {
      Node* temp = new Node;
      temp->ch = symb;
      root->children.push_back(temp);
      std::vector<char> new_vector(order);
      new_vector.erase(std::find(new_vector.begin(), new_vector.end(), symb));
      createTree(temp, new_vector);
    }
  }
}


void Tree::makePermutations(Node* root, std::vector<char> variation) {
  if (root != nullptr && root->ch != '#')
    variation.push_back(root->ch);
  if (root->children.empty())
    permutations.push_back(variation);
  for (Node* child : root->children) {
    makePermutations(child, variation);
  }
}

void Tree::createTreePermutations(const std::vector<char>& vector_) {
  createTree(root, vector_);
  makePermutations(root, {});
}

Tree::Tree(const std::vector<char>& vector_) {
  root = new Node;
  createTreePermutations(vector_);
}

std::vector<std::vector<char>> Tree::getPermutations() const {
  return permutations;
}
#endif  // INCLUDE_TREE_H_
