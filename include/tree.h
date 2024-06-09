// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class TreeNode {
public:
    char value;
    std::vector<TreeNode*> children;

    TreeNode(char val) : value(val) {}
};

class Tree {
public:
    Tree(const std::vector<char>& input) {
        buildTree(input);
    }

    std::vector<std::vector<char>> getAllPermutations() {
        std::vector<std::vector<char>> result;
        getPermutations(root, std::vector<char>(), result);
        return result;
    }

    std::vector<char> getPermutation(int index) {
        std::vector<std::vector<char>> allPermutations = getAllPermutations();
        if (index < 1 || index > allPermutations.size()) {
            return {}; // return empty vector if the index is out of range
        }
        return allPermutations[index - 1];
    }

private:
    TreeNode* root;

    void buildTree(const std::vector<char>& input) {
        root = new TreeNode(input[0]);
        buildTreeRecursive(root, input, 1);
    }

    void buildTreeRecursive(TreeNode* node, const std::vector<char>& input, int start) {
        if (start == input.size()) {
            return;
        }

        for (int i = start; i < input.size(); i++) {
            TreeNode* child = new TreeNode(input[i]);
            node->children.push_back(child);
            buildTreeRecursive(child, input, i + 1);
        }
    }

    void getPermutations(TreeNode* node, std::vector<char>& currentPermutation, std::vector<std::vector<char>>& result) {
        currentPermutation.push_back(node->value);

        if (node->children.empty()) {
            result.push_back(currentPermutation);
        } else {
            for (TreeNode* child : node->children) {
                getPermutations(child, currentPermutation, result);
                currentPermutation.pop_back();
            }
        }
    }
};
#include <vector>
#include <algorithm>

class TreeNode {
public:
    char value;
    std::vector<TreeNode*> children;

    TreeNode(char val) : value(val) {}
};

class Tree {
public:
    Tree(const std::vector<char>& input) {
        buildTree(input);
    }

    std::vector<std::vector<char>> getAllPermutations() {
        std::vector<std::vector<char>> result;
        getPermutations(root, std::vector<char>(), result);
        return result;
    }

    std::vector<char> getPermutation(int index) {
        std::vector<std::vector<char>> allPermutations = getAllPermutations();
        if (index < 1 || index > allPermutations.size()) {
            return {}; // return empty vector if the index is out of range
        }
        return allPermutations[index - 1];
    }

private:
    TreeNode* root;

    void buildTree(const std::vector<char>& input) {
        root = new TreeNode(input[0]);
        buildTreeRecursive(root, input, 1);
    }

    void buildTreeRecursive(TreeNode* node, const std::vector<char>& input, int start) {
        if (start == input.size()) {
            return;
        }

        for (int i = start; i < input.size(); i++) {
            TreeNode* child = new TreeNode(input[i]);
            node->children.push_back(child);
            buildTreeRecursive(child, input, i + 1);
        }
    }

    void getPermutations(TreeNode* node, std::vector<char>& currentPermutation, std::vector<std::vector<char>>& result) {
        currentPermutation.push_back(node->value);

        if (node->children.empty()) {
            result.push_back(currentPermutation);
        } else {
            for (TreeNode* child : node->children) {
                getPermutations(child, currentPermutation, result);
                currentPermutation.pop_back();
            }
        }
    }
};

#endif  // INCLUDE_TREE_H_
