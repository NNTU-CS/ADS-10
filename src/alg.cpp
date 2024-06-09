// Copyright 2022 NNTU-CS
#include "tree.h"
#include <vector>
#include <algorithm>

void generatePermutations(std::shared_ptr<TreeNode> node, std::vector<char>& current, std::vector<std::vector<char>>& permutations) {
    if (node->children.empty()) {
        permutations.push_back(current);
        return;
    }

    for (const auto& child : node->children) {
        current.push_back(child->value);
        generatePermutations(child, current, permutations);
        current.pop_back();
    }
}

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> permutations;
    std::vector<char> current;
    generatePermutations(tree.getRoot(), current, permutations);

    if (n <= 0 || n > static_cast<int>(permutations.size())) {
        return {};
    }
    return permutations[n - 1];
}
