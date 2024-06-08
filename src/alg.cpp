// Copyright 2022 NNTU-CS
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::string Permutations_string = tree[n - 1];
    std::vector<char> Permutationsdone;
    for (int i = 0; i < Permutations_string.length(); i++) {
        Permutationsdone.push_back(Permutations_string[i]);
    }
    return Permutationsdone;
}

struct Tree::Node {
    char nvalues;
    std::vector<Node*> newNNN;
};

void Tree::buildTree(Node* root, std::vector<char> trail) {
    if (!trail.size()) {
        return;
    }
    if (root->nvalue != '*') {
        for (auto i = trail.begin(); i < trail.end(); i++) {
            if (*i == root->nvalues) {
                trail.erase(i);
                break;
            }
        }
    }
    for (int i = 0; i < trail.size(); i++) {
        root->newNNN.push_back(new Node);
    }
    for (int i = 0; i < root->newNNN.size(); i++) {
        root->newNNN[i]->nvalues = trail[i];
    }
    for (int i = 0; i < root->newNNN.size(); i++) {
        buildTree(root->newNNN[i], trail);
    }
}

void Tree::generatePermutations(Node* parent, std::string symbol = "") {
    if (!parent->newNNN.size()) {
        symbol += parent->nvalues;
        permutations.push_back(symbol);
    }
    if (parent->nvalues != '*') {
        symbol += parent->nvalues;
    }
    for (int i = 0; i < parent->newNNN.size(); i++) {
        generatePermutations(parent->newNNN[i], symbol);
    }
}

Tree::Tree(const std::vector<char> value) {
    root = new Node();
    root->nvalues = '*';
    buildTree(root, value);
    generatePermutations(root);
}

std::string Tree::operator[] (unsigned int i) const {
    if (i >= permutations.size()) {
        return "";
    }
    if (i < 0) {
        throw std::string("wrong index lol");
    }
    return permutations[i];
}
