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
        char znach;
    };
    Node* root;

    std::vector <char> values;
    std::string elm;
    std::vector<char> transfr;
    std::vector<std::vector<char>> reslt;

 public:
    explicit Tree(std::vector <char> in) {
        values = in;
        elm.resize(in.size());
        transfr.resize(in.size());
        Node* root = new Node;
        root->znach = '*';
        transformm(in, -1, 0, root);
    }
    Node* createNode(char value) {
        Node* temp = new Node;
        temp->znach = value;
        return temp;
    }
    void transformm(std::vector<char> in, int k, int number, Node* root) {
        if (in.size() == 1) {
            reslt.push_back(transfr);
            return;
        }
        auto iter = in.cbegin();
        if (k >= 0) {
            number++;
            in.erase(iter + k);
        }
        for (int i = 0; i < in.size(); i++) {
            root->point.push_back(createNode(in[i]));
            transfr[number] = in[i];
            transformm(in, i, number, root->point[i]);
        }
    }
    std::vector<char> getPerm(Tree tree, int number) {
        if (number > reslt.size()) return {};
        return reslt[number - 1];
    }
};
#pragma once
