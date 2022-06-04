// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <string>
#include <vector>

class Tree {
 private:
    struct Node {
        char val;
        std::vector<Node*> ch;
    };
    Node* root;
    std::vector<std::string> numbs;

    void crTree(Node* root, std::vector<char> _numbs) {
        if (_numbs.size() == 0)
            return;
        if (root->val != '-') {
            for (auto k = _numbs.begin(); k != _numbs.end(); ++k) {
                if (*k == root->val) {
                    _numbs.erase(k);
                    break;
                }
            }
        }
        for (size_t k = 0; k < _numbs.size(); ++k) {
            root->ch.push_back(new Node);
        }
        for (size_t k = 0; k < root->ch.size(); ++k) {
            root->ch[k]->val = _numbs[k];
        }
        for (size_t k = 0; k < root->ch.size(); ++k) {
            crTree(root->ch[k], _numbs);
        }
    }
    void gperm(Node* root, std::string numb = "") {
        if (root->val != '-') {
            numb += root->val;
        }
        if (!root->ch.size()) {
            numb += root->val;
            numbs.push_back(numb);
            return;
        }
        for (size_t k = 0; k < root->ch.size(); ++k) {
            gperm(root->ch[k], numb);
        }
    }

 public:
    std::string operator[](int k) const {
        return numbs[k];
    }
    explicit Tree(std::vector<char> val) {
        root = new Node;
        root->val = '-';
        crTree(root, val);
        gperm(root);
    }
};
#endif  // INCLUDE_TREE_H_
