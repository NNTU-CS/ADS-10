// Copyright 2022 NNTU-CS
#include <algorithm>
#include <iostream>
#include <vector>
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> child;
    };

    Node* root = nullptr;
    std::vector<char> perm;
    void buildPermutationTree(std::vector<char> elements, Node* node) {
        for (auto element : elements) {
            Node* child = new Node;
            child->value = element;
            node->child.push_back(child);
            std::vector<char> remaining = elements;
            remaining.erase(std::remove(remaining.begin(),
                remaining.end(), element), remaining.end());
            buildPermutationTree(remaining, child);
        }
    }
    void generatePermutations(Node* node) {
        if (node->child.empty()) {
            perm.push_back(node->value);
            perms.push_back(perm);
            perm.pop_back();
        }
        for (Node* child : node->child) {
            perm.push_back(node->value);
            generatePermutations(child);
            perm.pop_back();
        }
    }

 public:
    std::vector<std::vector<char>> perms;
    explicit Tree(std::vector<char> elements) {
        root = new Node;
        root->value = 0;
        buildPermutationTree(elements, root);
        generatePermutations(root);
    }
};
#endif  // INCLUDE_TREE_H_
