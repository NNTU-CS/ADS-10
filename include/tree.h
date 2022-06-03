// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Tree {
 public:
    explicit Tree(std::vector<char> vn) {
        root = new Node;
        root->value = '#';
        Build_Tree(root, vn);
        Smena(root);
    }

    std::string operator[](int n) const {
        if (n >= modification.size()) {
            return "";
        }
        return modification[n];
    }

 private:
    struct Node{
        char value;
        std::vector<Node*> level;
    };
    Node* root;
    void Build_Tree(Node* root, std::vector<char> vect) {
        if (!vect.size()) {
            return;
        }
        if ('#' != root->value) {
            std::vector<char>::iterator pos =
                    std::find(vect.begin(), vect.end(), root->value);
            if (pos != vect.end()) {
                vect.erase(pos);
            }
        }
        for (int step = 0; step < vect.size(); step++) {
            root->level.push_back(new Node);
        }
        for (int step = 0; step < root->level.size(); ++step) {
            root->level[step]->value = vect[step];
        }
        for (unsigned int step = 0; step < root->level.size(); ++step) {
            Build_Tree(root->level[step], vect);
        }
    }

    std::vector<std::string> modification;

    void Smena(Node* root, std::string str = "") {
        if (!root->level.size()) {
            str += root->value;
            modification.push_back(str);
            return;
        }
        if ('#' != root->value) {
            str += root->value;
        }
        for (unsigned int step = 0; step < root->level.size(); ++step) {
            Smena(root->level[step], str);
        }
    }
};


#endif  // INCLUDE_TREE_H_
