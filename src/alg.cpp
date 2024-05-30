// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <vector>
#include  "tree.h"

void getPermutationHelper(TreeNode* node, int index, std::vector<char>& result) {
    if (node == nullptr) {
        return;
    }

    if (index == 0) {
        result.push_back(node->value);
        return;
    }

    --index;
    for (TreeNode* child : node->children) {
        getPermutationHelper(child, index, result);
        if (index == 0) {
            break;
        }
    }
}
std::vector<char> getPerm(Tree* tree, int index) {
    std::vector<char> result;
    getPermutationHelper(tree->root, index, result);
    return result;
}
