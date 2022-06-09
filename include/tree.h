// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#endif  // INCLUDE_TREE_H_
#include <vector>
#include <iostream>
#include <string>

class Tree {
 private:
    struct Node {
        std::vector<Node*> point;
        char value;
    };
    Node* root;

    std::vector <char> values;
    std::string elem;
    std::vector<char> transf;
    std::vector<std::vector<char>> res;

 public:
    explicit Tree(std::vector <char> in) {
        values = in;
        elem.resize(in.size());
        transf.resize(in.size());
        Node* root = new Node;
        root->value = '*';
        transformm(in, -1, 0, root);
    }
    Node* createNode(char value) {
        Node* temp = new Node;
        temp->value = value;
        return temp;
    }
    void transformm(std::vector<char> in, int k, int num, Node* root) {
        if (in.size() == 1) {
            res.push_back(transf);
            return;
        }
        auto iter = in.cbegin();
        if (k >= 0) {
            num++;
            in.erase(iter + k);
        }
        for (int i = 0; i < in.size(); i++) {
            root->point.push_back(createNode(in[i]));
            transf[num] = in[i];
            transformm(in, i, num, root->point[i]);
        }
    }
    std::vector<char> getPerm(Tree tree, int num) {
        if (num > res.size()) return {};
        return res[num - 1];
    }
};
#pragma once
