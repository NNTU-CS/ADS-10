// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>

struct Node {
    char data;
    std::vector<Node*> children;

    Node(char c) {
        data = c;
    }

    void addChild(Node* child) {
        children.push_back(child);
    }
};

void buildPermutationTree(std::vector<char>& symbols, Node* parent) {
    for (char symbol : symbols) {
        Node* child = new Node(symbol);
        parent->addChild(child);

        std::vector<char> remaining_symbols = symbols;
        remaining_symbols.erase(std::remove(remaining_symbols.begin(), remaining_symbols.end(), symbol), remaining_symbols.end());
        
        buildPermutationTree(remaining_symbols, child);
    }
}

void generatePermutations(Node* node, std::string& current_permutation, std::vector<std::string>& permutations) {
    current_permutation += node->data;

    if (node->children.empty()) {
        permutations.push_back(current_permutation);
        return;
    }

    for (Node* child : node->children) {
        generatePermutations(child, current_permutation, permutations);
    }

    current_permutation.pop_back();
}
#endif  // INCLUDE_TREE_H_
