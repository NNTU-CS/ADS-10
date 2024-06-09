// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

Tree::Tree(const std::vector<char>& elements) {
    if (!elements.empty()) {
        root = std::make_shared<TreeNode>('\0');
        buildTree(root, elements);
    }
}

void Tree::buildTree(std::shared_ptr<TreeNode> node, std::vector<char> elements) {
    if (elements.empty()) {
        return;
    }

    for (size_t i = 0; i < elements.size(); ++i) {
        std::vector<char> remainingElements = elements;
        remainingElements.erase(remainingElements.begin() + i);
        std::shared_ptr<TreeNode> childNode = std::make_shared<TreeNode>(elements[i]);
        node->children.push_back(childNode);
        buildTree(childNode, remainingElements);
    }
}

void Tree::traverseTree(std::shared_ptr<TreeNode> node, std::vector<char>& currentPermutation, std::vector<std::vector<char>>& permutations) const {
    if (node->value != '\0') {
        currentPermutation.push_back(node->value);
    }

    if (node->children.empty()) {
        permutations.push_back(currentPermutation);
    }
    else {
        for (auto& child : node->children) {
            traverseTree(child, currentPermutation, permutations);
            currentPermutation.pop_back();
        }
    }
}

std::vector<std::vector<char>> Tree::generateAllPermutations() const {
    std::vector<std::vector<char>> permutations;
    if (root) {
        std::vector<char> currentPermutation;
        traverseTree(root, currentPermutation, permutations);
    }
    return permutations;
}

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> permutations = tree.generateAllPermutations();

    if (n < 1 || n > permutations.size()) {
        return {};
    }

    return permutations[n - 1];
}
