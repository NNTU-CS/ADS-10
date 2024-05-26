// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

struct TreeNode {
    char value;
    bool isRoot = false;
    std::vector<TreeNode*> children;

    ~TreeNode() {
        for (auto child : children) {
            delete child;
        }
    }
};

class Tree {
 private:
    std::vector<std::vector<char>> permutations;
    TreeNode* root;

    TreeNode* createNode(char val) {
        TreeNode* node = new TreeNode;
        node->value = val;
        return node;
    }

    void addChildren(TreeNode* current,
    const std::vector<char>& remainingChars) {
        for (char ch : remainingChars) {
            TreeNode* newNode = createNode(ch);
            current->children.push_back(newNode);
            std::vector<char> nextChars = remainingChars;
            nextChars.erase(std::remove(nextChars.begin(),
              nextChars.end(), ch), nextChars.end());
            addChildren(newNode, nextChars);
        }
    }

    void gatherPermutations(TreeNode* current, 
    std::vector<char>& currentPerm) {
        if (!current->isRoot) {
            currentPerm.push_back(current->value);
        }
        if (current->children.empty()) {
            permutations.push_back(currentPerm);
        } else {
            for (TreeNode* child : current->children) {
                gatherPermutations(child, currentPerm);
                currentPerm.pop_back();
            }
        }
    }

 public:
    explicit Tree(const std::vector<char>& initialChars) {
        root = createNode('\0');
        root->isRoot = true;
        addChildren(root, initialChars);
        std::vector<char> currentPerm;
        gatherPermutations(root, currentPerm);
    }

    ~Tree() {
        delete root;
    }

    std::vector<std::vector<char>> getAllPermutations() const {
        return permutations;
    }
};

#endif  // INCLUDE_TREE_H_

