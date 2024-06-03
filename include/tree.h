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
            std::vector<char> rEl = elements;
            rEl.erase(std::remove(rEl.begin(), rEl.end(), element), rEl.end());
            buildTree(child, rEl);
        }
    }

    void gP(Node* nd, std::string curP, std::vector<std::string>* p) const {
        if (nd->value != '\0') {
            curP.push_back(nd->value);
        }
        if (nd->children.empty()) {
            p->push_back(curP);
            return;
        }
        for (size_t i = 0; i < nd->children.size(); ++i) {
            gP(nd->children[i], curP, p);
        }
    }
};

std::vector<char> gP(const Tree& tree, int index);

#endif  // INCLUDE_TREE_H_
