// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include <algorithm>
#include "tree.h"


void generatePermutations(std::shared_ptr<TreeNode> node, std::vector<char>& current_permutation, std::vector<std::vector<char>>& permutations);

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> permutations;
    std::vector<char> current_permutation;
    auto root = tree.getRoot();

    generatePermutations(root, current_permutation, permutations);
    
    if (n <= 0 || n > permutations.size()) {
        return {};
    }
    
    return permutations[n - 1];
}

void generatePermutations(std::shared_ptr<TreeNode> node, std::vector<char>& current_permutation, std::vector<std::vector<char>>& permutations) {
    if (node->value != '\0') {
        current_permutation.push_back(node->value);
    }
    
    if (node->children.empty()) {
        permutations.push_back(current_permutation);
    } else {
        for (auto child : node->children) {
            generatePermutations(child, current_permutation, permutations);
        }
    }
    
    if (!current_permutation.empty()) {
        current_permutation.pop_back();
    }
}


Tree::Tree(const std::vector<char>& elements) {
    if (!elements.empty()) {
        root = std::make_shared<TreeNode>('\0');
        buildTree(elements);
    }
}

void Tree::buildTree(const std::vector<char>& elements) {
    buildTreeRecursive(root, elements);
}

void Tree::buildTreeRecursive(std::shared_ptr<TreeNode> node, const std::vector<char>& elements) {
    if (elements.empty()) return;

    for (char c : elements) {
        auto child = std::make_shared<TreeNode>(c);
        node->children.push_back(child);

        std::vector<char> remaining_elements;
        for (char elem : elements) {
            if (elem != c) {
                remaining_elements.push_back(elem);
            }
        }

        buildTreeRecursive(child, remaining_elements);
    }
}
