// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class Tree {
 private:
    struct Node {
        std::vector<Node *> children;
        char value;
        Node(char val) : value(val) {}
    };
    Node *root;
    std::vector<std::vector<char>> permutations;

    void buildTree(Node *node, std::vector<char> values) {
        if (values.empty()) {
            return;
        }
        for (int i = 0; i < values.size(); i++) {
            std::vector<char> remainingValues = values;
            Node *child = new Node(values[i]);
            node->children.push_back(child);
            remainingValues.erase(remainingValues.begin() + i);
            buildTree(child, remainingValues);
        }
    }

    void generatePermutations(Node* node, std::vector<char>& current) {
        current.push_back(node->value);
        if (node->children.empty()) {
            permutations.push_back(current);
        } else {
            for (Node* child : node->children) {
                generatePermutations(child, current);
            }
        }
        current.pop_back();
    }

    void deleteTree(Node* node) {
        if (node) {
            for (Node* child : node->children) {
                deleteTree(child);
            }
            delete node;
        }
    }

 public:
    explicit Tree(const std::vector<char>& values) {
        root = new Node('\0');
        buildTree(root, values);
        std::vector<char> current;
        for (Node* child : root->children) {
            generatePermutations(child, current);
        }
    }

    ~Tree() {
        deleteTree(root);
    }

    std::vector<char> getPermutation(int index) const {
        if (index < 0 || index >= permutations.size()) {
            return std::vector<char>();
        }
        return permutations[index];
    }
};

#endif  // INCLUDE_TREE_H_
