// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> list;
    };
    Node* root;
    std::vector<std::string> perm;
    void Permutation(Node* root, std::string s = "") {
        if (!root->list.size()) {
            s += root->value;
            perm.push_back(s);
            return;
        }
        if (root->value != '*') {
            s += root->value;
        }
        for (size_t i = 0; i < root->list.size(); ++i) {
            Permutation(root->list[i], s);
        }
    }
    void constructTree(Node* root, std::vector<char> way) {
        if (!way.size()) {
            return;
        }
        if (root->value != '*') {
            for (auto i = way.begin(); i != way.end(); ++i) {
                if (*i == root->value) {
                    way.erase(i);
                    break;
                }
            }
        }
        for (size_t i = 0; i < way.size(); ++i) {
            root->list.push_back(new Node);
        }
        for (size_t i = 0; i < root->list.size(); ++i) {
            root->list[i]->value = way[i];
        }
        for (size_t i = 0; i < root->list.size(); ++i) {
            constructTree(root->list[i], way);
        }
    }

 public:
    std::string operator[](int i) const {
        if (i >= perm.size()) {
            return "";
        }
        return perm[i];
    }
    explicit Tree(std::vector<char> value) {
        root = new Node;
        root->value = '*';
        constructTree(root, value);
        Permutation(root);
    }
};
#endif  // INCLUDE_TREE_H_
