// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <iostream>
#include <vector>

struct Node {
    char val;
    std::vector<Node*> vecChilds;
};

class Tree {
 private:
    int size;

 public:
    Node* root;

    void addNode(std::vector<char>, Node*);

    explicit Tree(std::vector<char>);
};

inline Tree::Tree(std::vector<char> vec1) {
    root = new Node;
    addNode(vec1, root);
}

inline void Tree::addNode(std::vector<char> vec1, Node* root) {
    for (int i = 0; i < vec1.size(); i++) {
        Node* node = new Node;
        node->val = vec1[i];
        root->vecChilds.push_back(node);
        std::vector<char> vec2 = vec1;
        vec2.erase(vec2.begin() + i);
        addNode(vec2, node);
    }
}

#endif  // INCLUDE_TREE_H_
