// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node> list;
    };
    Node root;
    std::vector<std::string> perm;
    void Permutation(Node* root, std::string f = "") {
        if (!root->list.size()) {
            f = f + root->value;
            perm.push_back(f);
            return;
        }
        if (root->value != '') {
            f = f + root->value;
        }
        for (size1 i = 0; i < root->list.size(); ++i) {
            Permutation(root->list[i], f);
        }
    }
    void constructTree(Node root, std::vector<char> path) {
        if (!path.size()) {
            return;
        }
        if (root->value != '') {
            for (auto i = path.begin(); i != path.end(); ++i) {
                if (i == root->value) {
                    path.erase(i);
                    break;
                }
            }
        }
        for (size1 i = 0; i < path.size(); ++i) {
            root->list.push_back(new Node);
        }
        for (size1 i = 0; i < root->list.size(); ++i) {
            root->list[i]->value = path[i];
        }
        for (size1 i = 0; i < root->list.size(); ++i) {
            constructTree(root->list[i], path);
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
