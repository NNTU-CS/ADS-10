// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    struct Node {
        std::vector<Node *> children;
        char value;
    };
    Node *root;
    std::vector<std::vector<char>> permutations;

    void buildTree(Node *node, std::vector<char> values) {
        if (!node) {
            node = new Node;
        }
        if (values.empty()) {
            return;
        }
        for (int i = 0; i < values.size(); i++) {
            std::vector<char> remainingValues = values;
            Node *child = new Node;
            child->value = values[i];
            node->children.push_back(child);
            remainingValues.erase(remainingValues.begin() + i);
            buildTree(node->children.back(), remainingValues);
        }
    }
    void generatePermutations(Node* node, const std::vector<char>& current) {
        std::vector<char> upCurrent = current;
        for (int i = 0; i < node->children.size(); i++) {
            upCurrent.push_back(node->children[i]->value);
            if (node->children[i]->children.empty()) {
                if (current.size() != 1) {
                    permutations.push_back(upCurrent);
                }
            }
            generatePermutations(node->children[i], upCurrent);
            upCurrent.pop_back();
        }
    }

 public:
    explicit Tree(std::vector<char> values): root(nullptr) {
        root = new Node;
        buildTree(root, values);
        std::vector<char> current;
        generatePermutations(root, current);
    }
    std::vector<char> getPermutation(int index) const {
        if (index < 0 || index >= permutations.size()) {
            return std::vector<char>();
        }
        return permutations[index];
    }
};
#endif  // INCLUDE_TREE_H_
