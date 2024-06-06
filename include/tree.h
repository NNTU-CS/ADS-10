// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <iostream>
#include <vector>

struct Node {
    char value;
    std::vector<Node *> vecChild;
};

class Tree {
 private:
    int size;

 public:
    Node *root;

    void addNode(std::vector<char>, Node *);

    explicit Tree(std::vector<char>);
};

inline Tree::Tree(std::vector<char> vecBegin) {
    root = new Node;
    addNode(vecBegin, root);
}

inline void Tree::addNode(std::vector<char> vecBegin, Node *root) {
    for (int i = 0; i < vecBegin.size(); i++) {
        Node *node = new Node;
        node->value = vecBegin[i];
        root->vecChild.push_back(node);
        std::vector<char> vecEnd = vecBegin;
        vecEnd.erase(vecEnd.begin() + i);
        addNode(vecEnd, node);
    }
}

#endif  // INCLUDE_TREE_H_
