// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::string perm_string = tree[n - 1];
    std::vector<char> permisdone;
    for (int i = 0; i < perm_string.length(); i++) {
        permisdone.push_back(perm_string[i]);
    }
    return permisdone;
}

struct Tree::Node {
    char nvalue;
    std::vector<Node*> newN;
};

void Tree::createTree(Node* senior, std::vector<char> trail) {
    if (!trail.size()) {
        return;
    }
    if (senior->nvalue != '*') {
        for (auto i = trail.begin(); i < trail.end(); i++) {
            if (*i == senior->nvalue) {
                trail.erase(i);
                break;
            }
        }
    }
    for (int i = 0; i < trail.size(); i++) {
        senior->newN.push_back(new Node);
    }
    for (int i = 0; i < senior->newN.size(); i++) {
        senior->newN[i]->nvalue = trail[i];
    }
    for (int i = 0; i < senior->newN.size(); i++) {
        createTree(senior->newN[i], trail);
    }
}

void Tree::perms(Node* parent, std::string symb = "") {
    if (!parent->newN.size()) {
        symb += parent->nvalue;
        repl.push_back(symb);
    }
    if (parent->nvalue != '*') {
        symb += parent->nvalue;
    }
    for (int i = 0; i < parent->newN.size(); i++) {
        perms(parent->newN[i], symb);
    }
}

Tree::Tree(const std::vector<char> val) {
    senior = new Node();
    senior->nvalue = '*';
    createTree(senior, val);
    perms(senior);
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
#endif  // INCLUDE_TREE_H_
