#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "tree.h"

Tree::Tree(const std::vector<char>& elements) {
    root = new Node(0);
    buildTree(root, elements);
}

Tree::~Tree() {
    delete root;
}

void Tree::buildTree(Node* current, const std::vector<char>& elements) {
    if (elements.empty()) {
        return;
    }

    for (size_t i = 0; i < elements.size(); ++i) {
        std::vector<char> nextElems(elements.begin(), elements.end());
        nextElems.erase(nextElems.begin() + i);
        Node* child = new Node(elements[i]);
        current->children.push_back(child);

        buildTree(child, nextElems);
    }
}

void Tree::traverseTree(Node* current, std::vector<char>& permutation) {
    if (current->children.empty()) {
        permutations.push_back(permutation);
        return;
    }

    for (Node* child : current->children) {
        permutation.push_back(child->value);
        traverseTree(child, permutation);
        permutation.pop_back();
    }
}

std::vector<std::vector<char>> Tree::getPermutations() const {
    return permutations;
}

std::vector<char> Tree::getPermutation(int n) const {
    if (n > 0 && n <= permutations.size()) {
        return permutations[n - 1];
    }
    return {};
}
std::vector<char> getPerm(const Tree& tree, int n) {
    return tree.getPermutation(n);
}
