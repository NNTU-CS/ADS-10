// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

struct Node {
    std::vector<Node*> childs;
    char value = 0;
};

class Tree {
 public:
    Node* root;
    explicit Tree(std::vector<char>);
};
#endif  // INCLUDE_TREE_H_
