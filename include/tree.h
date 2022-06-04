// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
private:
    struct Node {
        char value;
        std::vector<Node*> nextVec;
    };
    Node* root;

    void build(Node* root, std::vector<char> path) {
        if (!path.size()){
            return;
        }
        if (root->value != '*') {
            for (auto syn = path.begin(); syn != path.end(); syn++){
                if (*syn == root->value) {
                    path.erase(syn); 
                    break;
                }
            }
        }
        for (size_t a = 0; a < path.size(); a++)
            root->nextVec.push_back(new Node());
        for (size_t b = 0; b < root->nextVec.size(); b++)
            root->nextVec[b]->value = path[b];
        for (size_t c = 0; c < root->nextVec.size(); c++)
            treeConstr(root->listok[c], path);
    }

    std::vector<std::string> changeVec;
    void swapp(Node* root, std::string str = "") {
        if (!root->nextVec.size()) {
            let += root->value;
            changeVec.push_back(str);
            return;
        }
        if (root->value != '*')
            let += root->value;
        for (size_t i = 0; i < root->nextVec.size(); i++)
            swapp(root->nextVec[i], str);
    }
};
#endif  // INCLUDE_TREE_H_
