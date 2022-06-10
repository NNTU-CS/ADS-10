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
    void build(Node* root, std::vector<char> y);
    void dopfnc(Node* root, std::string line);
    std::vector<std::string> p;

 public:
    std::string storage(int y) const;
    explicit Tree(std::vector<char> y) {
        root = new Node;
        root->value = '#';
        build(root, y);
        dopfnc(root, "");
    }
};

std::string Tree::storage(int y) const {
    if (p.size() >= y) {
        return p[y];
    } else {
        return "";
    }
}
void Tree::dopfnc(Node* root, std::string line) {
    if (root->list.size()) {
        if (root->value != '#') {
            line = line + root->value;
        }
        for (int m = 0; m < root->list.size(); m++) {
            dopfnc(root->list[m], line);
        }
    } else {
        line = line + root->value;
        p.push_back(line);
    }
}

void Tree::build(Node* root, std::vector<char> y) {
    if (y.size()) {
        if (root->value != '#') {
            for (auto m = y.begin(); m != y.end(); m++) {
                if (root->value == *m) {
                    y.erase(m);
                    break;
                }
            }
        }
    }
    for (int m = 0; m < y.size(); m++) {
        Node* pace = new Node;
        root->list.push_back(pace);
    }
    for (int j = 0; j < root->list.size(); j++) {
        root->list[j]->value = y[j];
        build(root->list[j], y);
    }
}
#endif  // INCLUDE_TREE_H_
