// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <memory>
#include <vector>

struct Node {
  char value;
  std::vector<std::shared_ptr<Node>> children;

  Node(char val) : value(val) {}
};

class Tree {
 public:
  std::shared_ptr<Node> root;

  Tree(const std::vector<char>& elements);
  void buildTree(std::shared_ptr<Node> node, std::vector<char> elements);
  std::vector<char> getPermutation(int n) const;

 private:
  void generatePermutations(std::shared_ptr<Node> node, std::vector<char>& path,
                            std::vector<std::vector<char>>& result) const;
  void getPermutationRecursive(std::shared_ptr<Node> node,
                               std::vector<char>& path, int& count, int target,
                               std::vector<char>& result) const;
};
#endif  // INCLUDE_TREE_H_
