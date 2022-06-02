// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Tree {
 public:
    explicit Tree(std::vector<char> in_v) {
        root = new Node;
        root->value = 'r';
        Build_Tree(root, in_v);
        Perestanovka(root);
    }

    std::string operator[](unsigned int n) const {
        if (n >= param_per.size()) {
            return "";
        }
        return param_per[n];
    }

 private:
    struct Node{
        char value;
        std::vector<Node*> level;
    };
    Node* root;
    void Build_Tree(Node* root, std::vector<char> _v) {
        if (!_v.size()) {
            return;
        }
        if ('r' != root->value) {
            std::vector<char>::iterator pos =
                    std::find(_v.begin(), _v.end(), root->value);
            if (pos != _v.end()) {
                _v.erase(pos);
            }
        }
        for (unsigned int step = 0; step < _v.size(); step++) {
            root->level.push_back(new Node);
        }
        for (unsigned int step = 0; step < root->level.size(); ++step) {
            root->level[step]->value = _v[step];
        }
        for (unsigned int step = 0; step < root->level.size(); ++step) {
            Build_Tree(root->level[step], _v);
        }
    }

    std::vector<std::string> param_per;

    void Perestanovka(Node* root, std::string str = "") {
        if (!root->level.size()) {
            str += root->value;
            param_per.push_back(str);
            return;
        }
        if ('r' != root->value) {
            str += root->value;
        }
        for (unsigned int step = 0; step < root->level.size(); ++step) {
            Perestanovka(root->level[step], str);
        }
    }
};


#endif  // INCLUDE_TREE_H_
