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
        getPerm(root, "", &permutations);
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

    void getPerm(Node* n, std::string cP, std::vector<std::string>* p) const {
        if (n->value != '\0') {
            cP.push_back(n->value);
        }
        if (n->children.empty()) {
            p->push_back(cP);
            return;
        }
        for (size_t i = 0; i < n->children.size(); ++i) {
            getPerm(n->children[i], cP, p);
        }
    }
};

std::vector<char> getPerm(const Tree& tree, int index);

#endif  // INCLUDE_TREE_H_
