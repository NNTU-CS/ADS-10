// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getperm(const tree& tree, int n) {
    std::string perm_string = tree[n - 1];
    std::vector<char> permisdone(perm_string.begin(), perm_string.end());
    return permisdone;
}
struct Tree::node {
    char nvalue;
    std::vector<node*> newn;
};
void Tree::createTree(node* senior, std::vector<char> trail) {
    if (trail.empty()) {
        return;
    }
    if (senior->nvalue != '*') {
        auto it = std::find(trail.begin(), trail.end(), senior->nvalue);
        if (it != trail.end()) {
            trail.erase(it);
        }
    }
    for (char n : trail) {
        senior->newn.push_back(new node{ n, {
        }
          });
    }
    for (node* n : senior->newn) {
        createTree(n, trail);
    }
}
void Tree::perms(node* parent, std::string symb = "") {
    if (parent->newn.empty()) {
        symb += parent->nvalue;
        repl.push_back(symb);
    }
    if (parent->nvalue != '*') {
        symb += parent->nvalue;
    }
    for (node* n : parent->newn) {
        perms(n, symb);
    }
}
Tree::Tree(const std::vector<char> val) {
    senior = new node{ '*', {} };
    createtree(senior, val);
    perms(senior);
}
std::string tree::operator[](unsigned int i) const {
    if (i >= repl.size()) {
        return "";
    }
    if (i < 0) {
        throw std::string("Error");
    }
    return repl[i];
}
