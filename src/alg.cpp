// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <vector>
#include  "tree.h"

void getPermHelper(TreeNode* node, int index, const std::vector<char>& result) {
    if (node == nullptr) {
        return;
    }

    if (index == 0) {
        result.push_back(node->value);
        return;
    }

    --index;
    for (TreeNode* child : node->children) {
        getPermHelper(child, index, result);
        if (index == 0) {
            break;
        }
    }
}
std::vector<char> getPerm(Tree* tree, int index) {
    std::vector<char> result;
    getPermHelper(tree->root, index, result);
    return result;
}
