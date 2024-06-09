// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>

class Tree {
 public:
  Tree(const std::string& elements);
  ~Tree();

  std::vector<std::vector<char>> generatePermutations() const;

 private:
  struct Node {
    char value;
    std::vector<Node*> children;
    Node(char val) : value(val) {}
  };

  Node* root;
  std::string elements;

  void buildTree(Node* node, const std::string& remaining_elements);
  void destroyTree(Node* node);
  void generatePermutations(Node* node, std::vector<char>& current,
                            std::vector<std::vector<char>>& result) const;
};

#endif  // INCLUDE_TREE_H_
