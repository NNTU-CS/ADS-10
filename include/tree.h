// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>
#include <algorithm>

class Node {
 public:
    std::vector<Node*> children;
    char value;

    explicit Node(char val) : value(val) {}

    ~Node() {
        for (auto child : children) {
            delete child;
        }
    }
};

class Tree {
 public:
    Node* Root1;

    explicit Tree(const std::vector<char>& elements) {
        Root1 = new Node('\0');
        buildTree(Root1, elements);
    }

    ~Tree() {
        delete Root1;
    }

    std::vector<std::string> getAllPermutations() const {
        std::vector<std::string> permutations;
        genPerm(Root1, "", &permutations);
        return permutations;
    }

 private:
    void buildTree(Node* node, const std::vector<char>& elements) {
        for (char element : elements) {
            Node* child = new Node(element);
            node->children.push_back(child);
            std::vector<char> el = elements;
            el.erase(std::remove(el.begin(), el.end(), element), el.end());
            buildTree(child, el);
        }
    }

    void genPerm(Node* n, std::string cur, std::vector<std::string>* p) const {
        if (n->value != '\0') {
            cur.push_back(n->value);
        }
        if (n->children.empty()) {
            p->push_back(cur);
            return;
        }
        for (auto child : n->children) {
            genPerm(child, cur, p);
        }
    }
};

std::vector<char> getPerm(const Tree& tree, int index);

#endif  // INCLUDE_TREE_H_
