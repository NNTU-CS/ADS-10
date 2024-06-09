// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class Tree {
 private:
    struct Node {
        std::vector<Node*> children;
        char value;
    };

    Node* root;
    std::vector<std::vector<char>> permutations;

    void buildTree(Node* node, std::vector<char> elements);
    void generatePermutations(Node* node, std::vector<char> current);

 public:
    explicit Tree(const std::vector<char>& input);
    std::vector<char> getPermutation(int index) const;
};

Tree::Tree(const std::vector<char>& input) : root(new Node) {
    buildTree(root, input);
    generatePermutations(root, {});
}

void Tree::buildTree(Node* node, std::vector<char> elements) {
    if (elements.empty()) {
        return;
    }

    for (size_t i = 0; i < elements.size(); ++i) {
        std::vector<char> remaining = elements;
        Node* child = new Node;
        child->value = elements[i];
        node->children.push_back(child);
        remaining.erase(remaining.begin() + i);
        buildTree(child, remaining);
    }
}

void Tree::generatePermutations(Node* node, std::vector<char> current) {
    for (Node* child : node->children) {
        current.push_back(child->value);
        if (child->children.empty()) {
            permutations.push_back(current);
        }
        generatePermutations(child, current);
        current.pop_back();
    }
}

std::vector<char> Tree::getPermutation(int index) const {
    if (index < 0 || index >= static_cast<int>(permutations.size())) {
        return {};
    }
    return permutations[index];
}

#endif  // INCLUDE_TREE_H_
