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
    std::string operator[](int i) const {
        if (i >= perm.size()) {
            return "";
        }
    return perm[i];
    }

    std::vector<char> GetPermutation(const Tree& tree, int n) {
        std::string res = tree[n-1];
        std::vector<char> perm;
        for (int i = 0; i < res.length(); ++i) {
            perm.push_back(res[i]);
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
    int i = 0;
        while (i < Numbs.size()) {
            root->current.push_back(new Node);
            i++;
        }
        for (int i = 0; i < root->current.size(); ++i) {
            root->current[i]->value = Numbs[i];
        }
        for (int i = 0; i < root->current.size(); ++i) {
            SetNode(root->current[i], Numbs);
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
        int i = 0;
        while (i < root->current.size()) {
            Prop(root->current[i], s);
            i++;
        }
    }
};

#endif  // INCLUDE_TREE_H_
