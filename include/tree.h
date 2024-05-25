// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

struct TreeNode {
    std::vector<TreeNode *> children;
    bool isRootNode = false;
    char value;

    ~TreeNode() {
        auto index = children.begin();
        while (index != children.end()) {
            delete *index;
            ++index;
        }
    }
};

class PermutationTree {
 private:
    std::vector<std::vector<char>> permutations;
    TreeNode *rootNode;

    TreeNode *createNode(char value) {
        TreeNode *newNode = new TreeNode;
        newNode->value = value;
        return newNode;
    }

    void insertChildren(TreeNode *currentNode, \
    const std::vector<char> &remainingChars) {
        auto index = remainingChars.begin();
        while (index != remainingChars.end()) {
            char currentChar = *index;
            TreeNode *newNode = createNode(currentChar);
            currentNode->children.push_back(newNode);
            std::vector<char> newRemainingChars(remainingChars);
            newRemainingChars.erase(std::remove(newRemainingChars.begin(), \
                newRemainingChars.end(), currentChar), \
                newRemainingChars.end());
            insertChildren(newNode, newRemainingChars);
            ++index;
        }
    }

    void collectPermutations(TreeNode *currentNode, \
    std::vector<char> currentPermutation) {
        if (!currentNode->isRootNode)
            currentPermutation.push_back(currentNode->value);
        if (currentNode->children.empty())
            permutations.push_back(currentPermutation);
        else {
            auto index = currentNode->children.begin();
            while (index != currentNode->children.end()) {
                collectPermutations(*index, currentPermutation);
                ++index;
            }
        }
    }

 public:
    explicit PermutationTree(const std::vector<char> &initialChars) {
        rootNode = createNode('\0');
        rootNode->isRootNode = true;
        std::vector<char> currentPermutation;
        collectPermutations(rootNode, currentPermutation);
    }

    ~PermutationTree() {
        delete rootNode;
    }

    std::vector<std::vector<char>> getAllPermutations() const {
        return permutations;
    }
};

#endif  // INCLUDE_TREE_H_
