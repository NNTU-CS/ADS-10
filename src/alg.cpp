// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::string perm_string = tree[n - 1];
    std::vector<char> result(perm_string.begin(), perm_string.end());
    return result;
}

struct Tree::Nodule {
    char nvalue;
    std::vector<Nodule*> newN;
};

void Tree::createTree(Nodule* miss, std::vector<char> trail) {
    if (!trail.size()) {
        return;
    }
    if (miss->nvalue != '*') {
        for (auto i = trail.begin(); i < trail.end(); i++) {
            if (*i == miss->nvalue) {
                trail.erase(i);
                break;
            }
        }
    }
    for (int i = 0; i < trail.size(); i++) {
        miss->newN.push_back(new Nodule);
    }
    for (int i = 0; i < miss->newN.size(); i++) {
        miss->newN[i]->nvalue = trail[i];
    }
    for (int i = 0; i < miss->newN.size(); i++) {
        createTree(miss->newN[i], trail);
    }
}

void Tree::perms(Nodule* parent, std::string symb = "") {
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
    miss = new Nodule();
    miss->nvalue = '*';
    createTree(miss, val);
    perms(miss);
}

std::string Tree::operator[](unsigned int i) const {
    if (i >= repl.size()) {
        return "";
    }
    if (i < 0) {
        throw std::string("Wrong index!!!");
    }
    return repl[i];
}
