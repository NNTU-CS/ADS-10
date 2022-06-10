// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <iostream>
#include <string>
class Tree {
 private:
    struct NodeDr {
        std::vector<NodeDr*> dot;
        char val_dr;
    };
    NodeDr* root;
    std::vector <char> val;
    std::vector<char> displace;
    std::string cell;
    std::vector<std::vector<char>> result;

 public:
    explicit Tree(std::vector <char> in) {
        val = in;
        cell.resize(in.size());
        displace.resize(in.size());
        NodeDr* root = new NodeDr;
        root->val_dr = '*';
        displacement(in, -1, 0, root);
    }

    NodeDr* addNodeDr(char val_dr) {
        NodeDr* temp = new NodeDr;
        temp->val_dr = val_dr;
        return temp;
    }
    void displacement(std::vector<char> in, int c, int number, NodeDr* root) {
        if (in.size() == 1) {
            result.push_back(displace);
            return;
        }
        auto iter = in.cbegin();
        if (c >= 0) {
            number++;
            in.erase(iter + c);
        }
        for (int i = 0; i < in.size(); i++) {
            root->dot.push_back(addNodeDr(in[i]));
            displace[number] = in[i];
            displacement(in, i, number, root->dot[i]);
        }
    }
    std::vector<char> getPerm(Tree tree, int number) {
        if (number > result.size()) return {};
        return result[number - 1];
    }
};
#pragma once
#endif  // INCLUDE_TREE_H_
