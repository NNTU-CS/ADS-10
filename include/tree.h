// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
class Tree {
 private:
    std::vector<std::string> stavlu;
    struct Node {
        char value;
        std::vector<Node*> detki;
    };
    Node* root;

    void NewNodes(Node* root, std::vector<char> value) {
        if (value.size() == 0) {
            return;
        }
        int b = 0;
        sort(value.begin(), value.end());
        if (root->value != '|') {
            size_t j = 0;
            auto i = value.begin();
            for (i; i != value.end(); i++) {
                j++;
                if (*i == root->value) {
                    value.erase(i);
                    break;
                } else {
                    j--;
                }
            }
        }
        while (b < value.size()) {
            root->detki.push_back(new Node);
            b++;
        }
        for (int i = 0; i < value.size(); i++) {
            root->detki[i]->value = value[i];
        }
        for (int i = 0; i < value.size(); i++) {
            NewNodes(root->detki[i], value);
        }
    }

    void perestavil(Node* root, std::string st = "") {
        if (!root->detki.size()) {
            st += root->value;
            stavlu.push_back(st);
            return;
        }
        if ('|' != root->value) {
            st += root->value;
        }
        for (int i = 0; i < root->detki.size(); i++) {
            perestavil(root->detki[i], st);
        }
    }

 public:
    std::string operator[](int num) const {
        return stavlu[num];
    }
    explicit Tree(std::vector<char> value) {
        root = new Node;
        root->value = '|';
        NewNodes(root, value);
        perestavil(root);
    }
};
#endif  // INCLUDE_TREE_H_
