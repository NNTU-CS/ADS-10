// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Node {
 public:
    char value;
    std::vector<Node*> children;
    explicit Node(char val) : value(val) {}
    ~Node() {
        for (auto child : children) {
            delete child;
        }
    }
};
class Tree {
 public:
    Node* root;
    std::vector<std::vector<char>> allPermutations;

    void buildTree(Node* node, const std::vector<char>& elements) {
        for (char element : elements) {
            Node* child = new Node(element);
            node->children.push_back(child);
            std::vector<char> el = elements;
            el.erase(std::remove(el.begin(), el.end(), element), el.end());
            buildTree(child, el);
        }
    }

    void genPermutations(Node* node, std::vector<char>* curPerm) {
        curPerm->push_back(node->value);

        if (node->children.empty()) {
            allPermutations.push_back(*curPerm);
        } else {
            for (auto child : node->children) {
                genPermutations(child, curPerm);
            }
        }
        curPerm->pop_back();
    }

 public:
    explicit Tree(const std::vector<char>& inputChars) : root(new Node(' ')) {
        buildTree(root, inputChars);
        std::vector<char> currentPermutation;
        for (auto child : root->children) {
            genPermutations(child, &currentPermutation);
        }
    }

    ~Tree() {
        delete root;
    }
    friend std::vector<char> getPerm(const Tree& tree, int n);
};

std::vector<char> getPerm(const Tree& tree, int index);

#endif  // INCLUDE_TREE_H_
