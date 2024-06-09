// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Tree {
 public:
    explicit Tree(char val) : value(val) {}
    ~Tree() {
        for (Tree* child : children) {
            delete child;
        }
    }
    void addChild(Tree* child) {
        children.push_back(child);
    }

    char value;
    std::vector<Tree*> children;
};

#endif  // INCLUDE_TREE_H_
