// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "tree.h"

void getPermutation(TreeNode* node, int& n, std::vector<char>& result, std::vector<char>& current) {
    if (node->children.empty()) {
        if (n == 0) {
            result = current;
        }
        --n;
        return;
    }

    for (TreeNode* child : node->children) {
        current.push_back(child->value);
        getPermutation(child, n, result, current);
        current.pop_back();
        if (!result.empty()) return;
    }
}

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> result;
    std::vector<char> current;
    int index = n - 1;  // n-1, потому что нумерация начинается с 0
    getPermutation(tree.getRoot(), index, result, current);
    return result;
}
