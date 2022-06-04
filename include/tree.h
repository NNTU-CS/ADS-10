// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <string>
#include <vector>
using std::string;
using std::vector;
class Tree {
 private:
    struct Node {
        char value;
        vector<Node*> iter;
    };
    Node* root;
    vector<string> iter2;
    void createTree(Node* root, vector<char> ch) {
        if (!ch.size()) {
            return;
        }
        if (root->value != '*') {
            ch.erase(find(ch.begin(), ch.end(), root->value));
        }
        for (size_t i = 0; i < ch.size(); i++)
            root->iter.push_back(new Node());
        for (size_t i = 0; i < root->iter.size(); i++) {
            root->iter[i]->value = ch[i];
            createTree(root->iter[i], ch);
        }
    }
    void Permut(Node* root, string str = "") {
        if (!root->iter.size()) {
            str += root->value;
            iter2.push_back(str);
            return;
        }
        if (root->value != '*') {
            str += root->value;
        }
        for (int i = 0; i < root->iter.size(); i++) {
            Permut(root->iter[i], str);
        }
    }

 public:
    string operator[](int i) const {
        if (i >= iter2.size()) {
            return "";
        }
        return iter2[i];
    }
    explicit Tree(vector<char> value) {
        root = new Node();
        root->value = '*';
        createTree(root, value);
        Permut(root);
    }
};
#endif  // INCLUDE_TREE_H_
