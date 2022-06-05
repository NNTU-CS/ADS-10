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
    std::string operator[](int b) const {
        if (b >= perm.size()) {
            return "";
        }
    return perm[b];
    }

    std::vector<char> GetPermutation(const Tree& tree, int n) {
        std::string r = tree[n-1];
        std::vector<char> perm;
        for (int b = 0; b < r.length(); ++b) {
            perm.push_back(r[b]);
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
            std::vector<char>::iterator ww = Numbs.begin();
            while (ww != Numbs.end()) {
                if (*ww == root->value) {
                    Numbs.erase(ww);
                    break;
                }
                ww++;
            }
        }
    int b = 0;
        while (b < Numbs.size()) {
            root->current.push_back(new Node);
           b++;
        }
        for (int b = 0; b < root->current.size(); ++b) {
            root->current[b]->value = Numbs[b];
        }
        for (int b = 0; b < root->current.size(); ++b) {
            SetNode(root->current[b], Numbs);
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
        int b = 0;
        while (b < root->current.size()) {
            Prop(root->current[b], s);
            b++;
        }
    }
};

#endif  // INCLUDE_TREE_H_

