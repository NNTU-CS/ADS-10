// Copyright 2022 NNTU-CS
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  struct Tree::Node {
    char value;
    std::vector<Node*> children;
};

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

    for (char c : remaining) {
        node->children.push_back(new Node);
    }

    for (int i = 0; i < node->children.size(); i++) {
        node->children[i]->value = remaining[i];
        buildTree(node->children[i], remaining);
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

Tree::Tree(const std::vector<char>& elements) {
    root = new Node();
    buildTree(root, elements);
    generatePermutations(root, "");
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

