// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

class Tree {
public:
    char data;
    std::vector<Tree*> children;

    Tree(char value) {
        data = value;
    }

    ~Tree() {
        for(Tree* child : children) {
            delete child;
        }
    }
};

void buildTree(Tree* root, std::vector<char> elements) {
    for (char element : elements) {
        Tree* child = new Tree(element);
        root->children.push_back(child);

        std::vector<char> remaining_elements = elements;
        remaining_elements.erase(std::find(remaining_elements.begin(), remaining_elements.end(), element));

        buildTree(child, remaining_elements);
    }
}

void traverseTree(Tree* node, std::vector<char>& permutation, std::vector<std::string>& permutations) {
    permutation.push_back(node->data);

    if (node->children.empty()) {
        std::string perm;
        for (char c : permutation) {
            perm += c;
        }
        permutations.push_back(perm);
    } else {
        for (Tree* child : node->children) {
            traverseTree(child, permutation, permutations);
        }
    }

    permutation.pop_back();
}

std::vector<std::string> generatePermutations(const Tree& tree) {
    std::vector<std::string> permutations;
    std::vector<char> permutation;
    traverseTree(const_cast<Tree*>(&tree), permutation, permutations);
    return permutations;
}
#endif  // INCLUDE_TREE_H_
