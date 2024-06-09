// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <cstddef>

class Tree {
private:
    struct Node {
        char value;
        std::vector<Node*> children;

        Node(char val) : value(val) {}

        ~Node() {
            for (auto child : children) {
                delete child;
            }
        }
    };

    Node* root;
    std::vector<std::vector<char>> permutations;

    void buildTreeRecursive(Node* node, const std::vector<char>& values);
    void generatePermutationsRecursive(Node* node, std::vector<char> current);

public:
    explicit Tree(const std::vector<char>& values);
    ~Tree();

    std::vector<char> getPermutation(int index) const;
};

Tree::Tree(const std::vector<char>& values) {
    root = new Node(0);
    buildTreeRecursive(root, values);
    std::vector<char> current;
    generatePermutationsRecursive(root, current);
}

Tree::~Tree() {
    delete root;
}

void Tree::buildTreeRecursive(Node* node, const std::vector<char>& values) {
    if (values.empty()) {
        return;
    }

    for (size_t i = 0; i < values.size(); ++i) {
        std::vector<char> nextElems(values.begin(), values.end());
        nextElems.erase(nextElems.begin() + i);

        Node* child = new Node(values[i]);
        node->children.push_back(child);

        buildTreeRecursive(child, nextElems);
    }
}

void Tree::generatePermutationsRecursive(Node* node, std::vector<char> current) {
    for (int i = 0; i < node->children.size(); i++) {
        current.push_back(node->children[i]->value);
        if (node->children[i]->children.empty()) {
            permutations.push_back(current);
        }
        generatePermutationsRecursive(node->children[i], current);
        current.pop_back();
    }
}

std::vector<char> Tree::getPermutation(int index) const {
    if (index < 0 || index >= permutations.size()) {
        return std::vector<char>();
    }
    return permutations[index];
}

#endif  // INCLUDE_TREE_H_
