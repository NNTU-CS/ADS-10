// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>

class Tree {
 public:
    explicit Tree(std::vector<char> x) {
        root = new Node;
        root->value = '/';
        SetNode(root, x);
        Prop(root);
    }
    std::string operator[](int j) const {
        if (j >= perm.size()) {
            return "";
        }
    return perm[j];
    }

    std::vector<char> GetPermutation(const Tree& tree, int n) {
        std::string res = tree[n-1];
        std::vector<char> perm;
        for (int j = 0; j < res.length(); ++j) {
            perm.push_back(res[j]);
        }
      return perm;
    }

 private:
    struct Node {
        char value;
        std::vector<Node*> current;
    };
    Node* root;
    std::vector<std::string> perm;
    void SetNode(Node* root, std::vector<char> Numbs) {
    if (!Numbs.size()) {
     return;
    }
        if (root->value != '/') {
            std::vector<char>::iterator v = Numbs.begin();
            while (v != Numbs.end()) {
                if (*v == root->value) {
                    Numbs.erase(v);
                    break;
                }
                v++;
            }
        }
    int j = 0;
        while (j < Numbs.size()) {
            root->current.push_back(new Node);
            j++;
        }
        for (int j = 0; j < root->current.size(); ++j) {
            root->current[j]->value = Numbs[j];
        }
        for (int j = 0; j < root->current.size(); ++j) {
            SetNode(root->current[j], Numbs);
        }
    }

    void Prop(Node* root, std::string s = "") {
        if (!root->current.size()) {
            s = s + root->value;
            perm.push_back(s);
            return;
        }
        if (root->value != '/') {
            s = s + root->value;
        }
        int j = 0;
        while (j < root->current.size()) {
            Prop(root->current[j], s);
            j++;
        }
    }
};

#endif  // INCLUDE_TREE_H_
