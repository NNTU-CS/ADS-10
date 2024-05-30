// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <string>
#include <vector>

class TreeNode {
 public:
    char value;
    std::vector<TreeNode*> children;

    explicit TreeNode(char value) : value(value) {}
};

class Tree {
 public:
    TreeNode* root;

    explicit Tree(const std::string& symbols) {
        root = new TreeNode(symbols[0]);
        for (size_t i = 1; i < symbols.size(); ++i) {
            addChild(root, symbols[i]);
        }
    }

    void addChild(TreeNode* node, char value) {
        TreeNode* newNode = new TreeNode(value);
        node->children.push_back(newNode);
    }
};

#endif  // INCLUDE_TREE_H_
