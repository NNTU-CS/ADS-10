// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

struct node {
    char a;
    std::vector<node*> child;
    explicit node(char c) : a(c) {};
};

class Tree {
 public:
    explicit Tree(const std::vector<char>& characters) {
        root = new node('\0');
        buildTree(characters, root);
    }

    std::vector<std::vector<char>> getPermut() const {
        std::vector<std::vector<char>> permutations;
        std::vector<char> current;
        generatePermut(root, current, &permutations);
        return permutations;
    }

 private:
    node* root;

    void buildTree(const std::vector<char>& characters, node* parent) {
        for (char c : characters) {
            node* child = new node(c);
            parent->child.push_back(child);
            std::vector<char> remainingChars(characters);
            remainingChars.erase(std::find(remainingChars.begin(), remainingChars.end(), c));
            buildTree(remainingChars, child);
        }
    }

    void generatePermut(node* current, std::vector<char>& currentPermutation, std::vector<std::vector<char>>* permutations) const {
        currentPermutation.push_back(current->a);
        if (current->child.empty()) {
            permutations->push_back(currentPermutation);
        } else {
            for (node* child : current->child) {
                generatePermut(child, currentPermutation, permutations);
            }
        }
        currentPermutation.pop_back();
    }
}
#endif  // INCLUDE_TREE_H_
