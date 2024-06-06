// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

#include "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    return tree.getPerm(n);
}
src/tree.cpp:

#include "tree.h"
#include <algorithm>

Tree::Tree(const std::vector<char>& elements) {
    buildTree(elements, 0);
}

void Tree::buildTree(const std::vector<char>& elements, int level) {
    if (level == elements.size()) {
        currentPerm = elements;
        return;
    }

    for (int i = level; i < elements.size(); i++) {
        std::swap(elements[level], elements[i]);
        Tree* child = new Tree(elements);
        children.push_back(child);
        std::swap(elements[level], elements[i]);
    }
}

void Tree::generatePermutations(std::vector<char>& perm, int level) const {
    if (level == currentPerm.size()) {
        perm = currentPerm;
        return;
    }

    for (Tree* child : children) {
        child->generatePermutations(perm, level + 1);
    }
}

std::vector<char> Tree::getPerm(int n) const {
    std::vector<char> perm;
    int count = 0;
    generatePermutations(perm, 0);

    if (n > 0 && n <= perm.size()) {
        return perm[n - 1];
    } else {
        return {};
    }
}
