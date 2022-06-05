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
    std::string operator[](int c) const {
        if (c >= perm.size()) {
            return "";
        }
    return perm[c];
    }

    std::vector<char> GetPermutation(const Tree& tree, int n) {
        std::string result = tree[n-1];
        std::vector<char> perm;
        for (int c = 0; c < result.length(); ++c) {
            perm.push_back(result[c]);
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
            std::vector<char>::iterator q = Numbs.begin();
            while (q != Numbs.end()) {
                if (*q == root->value) {
                    Numbs.erase(q);
                    break;
                }
                q++;
            }
        }
    int c = 0;
        while (c < Numbs.size()) {
            root->current.push_back(new Node);
           c++;
        }
        for (int c = 0; c < root->current.size(); ++c) {
            root->current[c]->value = Numbs[c];
        }
        for (int c = 0; c < root->current.size(); ++c) {
            SetNode(root->current[c], Numbs);
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
        int c = 0;
        while (c < root->current.size()) {
            Prop(root->current[c], s);
            c++;
        }
    }
};

#endif  // INCLUDE_TREE_H_

