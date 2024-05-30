// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <iostream>

class Node {
 public:
    int value;
    std::vector<Node*> ch;

    explicit Node(int value) : value(value) {}
};

class Tree {
 private:
    Node* root;
    explicit Tree(const std::vector<char>& values) {
        root = buildTree(values);
    }

 public:
    Node* buildTree(const std::vector<char>& values) {
        if (values.empty()) {
            return nullptr;
        }

        std::vector<std::vector<Node*>> levels;
        levels.push_back({ new Node(values[0]) });

        for (int i = 1; i < values.size(); i++) {
            std::vector<Node*> currentLevel;
            for (int j = 0; j < levels[levels.size() - 1].size(); j++) {
                Node* node = levels[levels.size() - 1][j];
                node->ch.push_back(new Node(values[i]));
                currentLevel.push_back(node->ch.back());
            }
            levels.push_back(currentLevel);
        }
        return levels[0][0];
    }
};

#endif  // INCLUDE_TREE_H_
