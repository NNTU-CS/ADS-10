// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>
#include <algorithm>

struct Node {
    std::vector<Node*> children;
    char value;

    explicit Node(char val) : value(val) {}

    ~Node() {
        for (size_t i = 0; i < children.size(); ++i) {
            delete children[i];
        }
    }
};

class Tree {
 public:
    Node* root;

    explicit Tree(const std::vector<char>& elements) {
        root = new Node('\0');
        buildTree(root, elements);
    }

    ~Tree() {
        delete root;
    }

    std::vector<std::string> getAllPermutations() const {
        std::vector<std::string> permutations;
        genPerm(root, "", &permutations);
        return permutations;
    }

 private:
    void buildTree(Node* node, const std::vector<char>& elements) {
        for (char element : elements) {
            Node* child = new Node(element);
            node->children.push_back(child);
            std::vector<char> remEl = elements;
            remEl.erase(std::remove(remEl.begin(), remEl.end(), element), remEl.end());
            buildTree(child, remEl);
        }
    }

    void genPerm(Node* node, std::string curPerm, std::vector<std::string>* permutations) const {
        if (node->value != '\0') {
            curPerm.push_back(node->value);
        }
        if (node->children.empty()) {
            permutations->push_back(curPerm);
            return;
        }
        for (auto child : n->children) {
            genPerm(child, cur, p);
        }
    }
};

std::vector<char> getPerm(const Tree& tree, int index);

#endif  // INCLUDE_TREE_H_
