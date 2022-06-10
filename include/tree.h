// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>

class Tree {
 private:
    struct Node {
        char v;
        std::vector<Node*> ch;
    };
    Node* root;
    std::vector<std::string> numbs;

    void crTree(Node* root, std::vector<char> _numbs) {
        if (_numbs.size() == 0)
            return;
        if (root->v != '-') {
            for (auto p = _numbs.begin(); p != _numbs.end(); ++p) {
                if (*p == root->v) {
                    _numbs.erase(p);
                    break;
                }
            }
        }
        for (size_t p = 0; p < _numbs.size(); ++p) {
            root->ch.push_back(new Node);
        }
        for (size_t p = 0; p < root->ch.size(); ++p) {
            root->ch[p]->v = _numbs[p];
        }
        for (size_t p = 0; p < root->ch.size(); ++p) {
            crTree(root->ch[p], _numbs);
        }
    }
    void gperm(Node* root, std::string numb = "") {
        if (root->v != '-') {
            numb += root->v;
        }
        if (!root->ch.size()) {
            numb += root->v;
            numbs.push_back(numb);
            return;
        }
        for (size_t p = 0; p < root->ch.size(); ++p) {
            gperm(root->ch[p], numb);
        }
    }

 public:
    std::string operator[](int p) const {
        return numbs[p];
    }
    explicit Tree(std::vector<char> v) {
        root = new Node;
        root->v = '-';
        crTree(root, v);
        gperm(root);
    }
};
#endif  // INCLUDE_TREE_H_
