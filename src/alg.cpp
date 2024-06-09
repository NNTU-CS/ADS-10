// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::string perm_string = tree[n - 1];
    std::vector<char> permuts;
    for (int i = 0; i < perm_string.length(); i++) {
        permuts.push_back(perm_string[i]);
    }
    return permuts;
}

struct Tree::Node {
    char nvalue;
    std::vector<Node*> newN;
};

void Tree::createTree(Node* fort, std::vector<char> trail) {
    if (!trail.size()) {
        return;
    }
    if (fort->nvalue != '*') {
        for (auto i = trail.begin(); i < trail.end(); i++) {
            if (*i == fort->nvalue) {
                trail.erase(i);
                break;
            }
        }
    }
    for (int i = 0; i < trail.size(); i++) {
        fort->newN.push_back(new Node);
    }
    for (int i = 0; i < fort->newN.size(); i++) {
        fort->newN[i]->nvalue = trail[i];
    }
    for (int i = 0; i < fort->newN.size(); i++) {
        createTree(fort->newN[i], trail);
    }
}

void Tree::generatePermutations(Node* parent, std::string symbs = "") {
    if (!parent->newN.size()) {
        symbs += parent->nvalue;
        repl.push_back(symbs);
    }
    if (parent->nvalue != '*') {
        symbs += parent->nvalue;
    }
    for (int i = 0; i < parent->newN.size(); i++) {
        generatePermutations(parent->newN[i], symbs);
    }
}

Tree::Tree(const std::vector<char> val) {
    fort = new Node();
    fort->nvalue = '*';
    createTree(fort, val);
    generatePermutations(fort);
}

std::string Tree::operator[] (unsigned int i) const {
    if (i >= repl.size()) {
        return "";
    }
    if (i < 0) {
        throw std::string("Wrong index!!!");
    }
    return repl[i];
}
