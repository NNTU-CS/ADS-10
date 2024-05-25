// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    char value;
    std::vector<Node*> children;

    Node(char val) : value(val) {}
    ~Node() {
        for (auto child : children) {
            delete child;
        }
    }
};

class Tree {
 private:
    Node* root;
    std::vector<std::vector<char>> permutations;

    void buildTree(Node* current, const std::vector<char>& elements);
    void traverseTree(Node* current, std::vector<char>& permutation);

 public:
    explicit Tree(const std::vector<char>& elements);
    ~Tree();
    std::vector<std::vector<char>> getPermutations() const;
    std::vector<char> getPermutation(int n) const;
};

#endif  // INCLUDE_TREE_H_
