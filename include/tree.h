// Copyright 2022 NNTU-CS
#ifndef TREE_H
#define TREE_H

#include <vector>
#include <memory>

class TreeNode {
public:
    char value;
    std::vector<std::shared_ptr<TreeNode>> children;

    TreeNode(char val) : value(val) {}
};

class Tree {
private:
    std::shared_ptr<TreeNode> root;
    void buildTree(std::shared_ptr<TreeNode> node, std::vector<char> elements);

public:
    Tree(const std::vector<char>& elements);
    std::shared_ptr<TreeNode> getRoot() const { return root; }
};

#endif // TREE_H
