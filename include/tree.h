// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <memory>

class TreeNode {
public: 
    char value;
    std::vector<std::shared_ptr<TreeNode>> children;

    explicit TreeNode(char val) : value(val) {}
};

class Tree {
public: 
    explicit Tree(const std::vector<char>& elements);
    std::vector<std::vector<char>> generateAllPermutations() const;

private: 
    std::shared_ptr<TreeNode> root;
    void buildTree(std::shared_ptr<TreeNode> node, std::vector<char> elements);
        void traverseTree(std::shared_ptr<TreeNode> node,
        std::vector<char>* currentPermutation,
        std::vector<std::vector<char>>* permutations) const;
};
};

std::vector<char> getPerm(const Tree& tree, int n);

#endif  // INCLUDE_TREE_H_
