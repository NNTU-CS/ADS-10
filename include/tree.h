// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    struct Node {
        char symb;
        std::vector<Node*> children;
    };
    friend void recPerm(Tree::Node* node, int tree_size, int n,
    std::vector<char>* vec);
    friend std::vector<char> getPerm(const Tree& tree, int n);
    Node* createNode(const std::vector<char>& vec, char data);
    void deleteNode(Node* node);
    Node* root;
 public:
    explicit Tree(const std::vector<char>& vec);
    ~Tree();
};
#endif  // INCLUDE_TREE_H_
