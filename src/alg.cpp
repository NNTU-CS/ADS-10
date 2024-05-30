// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <vector>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int index) {
    Node* current = tree.root;
    std::vector<char> result;

    for (int i = 0; i < tree.root->children.size(); i++) {
        if (i == index) {
            result.push_back(current->children[i]->value);
            return result;
        }
        current = current->children[i];
    }

    return {};
}
