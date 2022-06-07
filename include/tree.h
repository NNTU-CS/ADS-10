// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> list;
    };
    Node* root = nullptr;
    void buildTree(Node* root, std::vector<char> y);
    void dop(Node* root, std::string line);
    std::vector<std::string> p;

 public:
    std::string storage(int y) const;
    explicit Tree(std::vector<char> y) {
        root = new Node;
        root->value = '*';
        buildTree(root, y);
        dop(root, "");
    }
};

std::string Tree::storage(int y) const {
    if (p.size() >= y) {
        return p[y];
    } else {
        return "";
    }
}
void Tree::dop(Node* root, std::string line) {
    if (root->list.size()) {
        if (root->value != '*') {
            line = line + root->value;
        }
        for (int i = 0; i < root->list.size(); ++i) {
            dop(root->list[i], line);
        }
    } else {
        line = line + root->value;
        p.push_back(line);
    }
}

void Tree::buildTree(Node* root, std::vector<char> y) {
    if (y.size()) {
        if (root->value != '*') {
            for (auto i = y.begin(); i != y.end(); ++i) {
                if (root->value == *i) {
                    y.erase(i);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < y.size(); ++i) {
        Node* pace = new Node;
        root->list.push_back(pace);
    }
    for (int j = 0; j < root->list.size(); ++j) {
        root->list[j]->value = y[j];
        buildTree(root->list[j], y);
    }
}

#endif  // INCLUDE_TREE_H_
