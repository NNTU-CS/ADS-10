// Copyright 2022 NNTU-CS
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
#include <algorithm>
#include <vector>

std::vector<char> getPerm(const Tree& tree, int n) {
    std::string perm_string = tree[n - 1];
    std::vector<char> perm;
    for (char c : perm_string) {
        perm.push_back(c);
    }
    return perm;
}

struct Tree::Node {
    char value;
    std::vector<Node*> children;
};

Tree::Tree() {
    root = new Node();
}

Tree::Tree(const std::vector<char>& elements) {
    buildTree(root, elements);
    generatePermutations(root, "");
}

void Tree::buildTree(Node* node, std::vector<char> elements) {
    if (elements.empty()) {
        return;
    }

    node->value = *std::min_element(elements.begin(), elements.end());
    std::vector<char> remaining;
    for (char c : elements) {
        if (c != node->value) {
            remaining.push_back(c);
        }
    }

    if (!remaining.empty()) {
        for (char c : remaining) {
            node->children.push_back(new Node);
        }

        for (int i = 0; i < node->children.size(); i++) {
            node->children[i]->value = remaining[i];
            buildTree(node->children[i], remaining);
        }
    }
}

void Tree::generatePermutations(Node* node, std::string current) {
    if (node->children.empty()) {
        permutations.push_back(current + node->value);
    } else {
        for (Node* child : node->children) {
            generatePermutations(child, current + node->value);
        }
    }
}

std::string Tree::operator[](unsigned int index) const {
    if (index >= permutations.size()) {
        return "";
    }
    if (index < 0) {
        throw std::string("Wrong index!!!");
    }
    return permutations[index];
}
