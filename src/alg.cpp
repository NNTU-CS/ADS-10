// Copyright 2022 NNTU-CS
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::string permStr = tree[n - 1];
    std::vector<char> perm1;
    for (int i = 0; i < permStr.length(); i++) {
        perm1.push_back(permStr[i]);
    }
    return perm1;
}

struct Tree::Node {
    char value1;
    std::vector<Node*> ne1;
};

void Tree::createTree(Node* s, std::vector<char> tr) {
    if (!tr.size()) {
        return;
    }
    if (s->value1 != '*') {
        for (auto i = tr.begin(); i < tr.end(); i++) {
            if (*i == s->value1) {
                tr.erase(i);
                break;
            }
        }
    }
    for (int i = 0; i < tr.size(); i++) {
        s->ne1.push_back(new Node);
    }
    for (int i = 0; i < s->ne1.size(); i++) {
        s->ne1[i]->value1 = tr[i];
    }
    for (int i = 0; i < s->ne1.size(); i++) {
        createTree(s->ne1[i], tr);
    }
}

void Tree::perems(Node* parent, std::string symb = "") {
    if (!parent->ne1.size()) {
        symb += parent->value1;
        repl.push_back(symb);
    }
    if (parent->value1 != '*') {
        symb += parent->value1;
    }
    for (int i = 0; i < parent->ne1.size(); i++) {
        perems(parent->ne1[i], symb);
    }
}

Tree::Tree(const std::vector<char> val) {
    s = new Node();
    s->value1 = '*';
    createTree(s, val);
    perems(s);
}

std::string Tree::operator[] (unsigned int i) const {
    if (i >= p.size()) {
        return "";
    }
    if (i < 0) {
        throw std::string("Неправильный индекс");
    }
    return p[i];
}
