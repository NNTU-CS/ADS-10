// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <memory>

class TreeNode {
 public:
    explicit TreeNode(char val) : value(val) {}
    char value;
    std::vector<std::shared_ptr<TreeNode>> children;
};

class Tree {
 public:
    explicit Tree(const std::vector<char>& elements);
    std::shared_ptr<TreeNode> getRoot() const { return root; }
    void buildTree(const std::vector<char>& elements);

 private:
    std::shared_ptr<TreeNode> root;
    void buildTreeRecursive(std::shared_ptr<TreeNode> node, const std::vector<char>& elements);
};

#endif  // INCLUDE_TREE_H_
