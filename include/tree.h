// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Node {
 public:
    std::vector<Node*> children;
    char value;

    Node(char val) : value(val) {}

    ~Node() {
        for (auto child : children) {
            delete child;
        }
    }
};

class Tree {
 public:
    Node* root;

    Tree(const std::vector<char>& elements) {
        root = new Node('\0');
        buildTree(root, elements);
    }

    ~Tree() {
        delete root;
    }
 private:
    void buildTree(Node* node, const std::vector<char>& elements) {
        for (char element : elements) {
            Node* child = new Node(element);
            node->children.push_back(child);
            std::vector<char> remainingElements = elements;
            remainingElements.erase(std::remove(remainingElements.begin(), remainingElements.end(), element), remainingElements.end());
            buildTree(child, remainingElements);
        }
    }
};

void generatePermutations(Node* node, std::string current, std::vector<std::string>& permutations) {
    if (node->value != '\0') {
        current.push_back(node->value);
    }
    if (node->children.empty()) {
        permutations.push_back(current);
        return;
    }
    for (auto child : node->children) {
        generatePermutations(child, current, permutations);
    }
}

std::vector<std::string> getAllPermutations(Tree& tree) {
    std::vector<std::string> permutations;
    generatePermutations(tree.root, "", permutations);
    return permutations;
}

#endif  // INCLUDE_TREE_H_
