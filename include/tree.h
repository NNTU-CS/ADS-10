// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class TreeNode {
 public:
    char value;
    std::vector<TreeNode*> children;

    explicit TreeNode(char val) : value(val) {}
    ~TreeNode() {
        for (TreeNode* child : children) {
            delete child;
        }
    }
};

class Tree {
 private:
    TreeNode* root;
    void buildTree(TreeNode* node, const std::vector<char>& elements) {
        if (elements.empty()) return;

        for (char el : elements) {
            TreeNode* child = new TreeNode(el);
            node->children.push_back(child);

            std::vector<char> remaining_elements = elements;
            remaining_elements.erase(
                std::remove(
                    remaining_elements.begin(),
                    remaining_elements.end(), el),
                remaining_elements.end());

            buildTree(child, remaining_elements);
        }
    }

 public:
    explicit Tree(const std::vector<char>& elements) {
        if (elements.empty()) {
            root = nullptr;
        } else {
            root = new TreeNode(0);  // фиктивный корневой узел
            buildTree(root, elements);
        }
    }

    ~Tree() {
        delete root;
    }

    TreeNode* getRoot() const {
        return root;
    }
};

#endif  // INCLUDE_TREE_H_
