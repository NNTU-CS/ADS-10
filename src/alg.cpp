// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <cstdlib>
#include "tree.h"

static std::vector<char> removeFirst(std::vector<char> a, char c) {
    std::vector<char> b = a;
    for (std::vector<char>::iterator it = b.begin(); it != b.end(); it++) {
        if (*it == c) {
            b.erase(it);
            return b;
        }
    }
    throw std::string("char not found");
}

static void addChilds(Node* n, std::vector<char> in) {
    for (char c : in) {
        Node* child = new Node();
        child->value = c;
        n->childs.push_back(child);
        addChilds(child, removeFirst(in, c));
    }
}

static void getVariations(Node n, std::string a, const std::vector<std::string>& r) {
    a += n.value;
    if (n.childs.empty()) {
        r.push_back(a);
        return;
    }
    for (auto c : n.childs) {
        getVariations(*c, a, r);
    }
}

std::vector<std::string> getVariations(Node root) {
    std::vector<std::string> r;
    for (Node* n : root.childs) {
        getVariations(*n, std::string(), r);
    }
    return r;
}

Tree::Tree(std::vector<char> in) {
    root = new Node();
    addChilds(root, in);
}

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> b;
    auto v = getVariations(*tree.root);
    if (n > v.size()) {
        return b;
    }
    std::string a = v[n - 1];
    for (auto c : a) {
        b.push_back(c);
    }
    return b;
}
