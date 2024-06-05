// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>
class Tree {
 public:
    struct Node {
        char value;
        int count;
        Node** sons;
    };

 private:
    Node* root = nullptr;
    Node* node;
    std::vector<std::vector<char>> rer;
    void add(Node* node, std::vector<char> value) {
        node->count = value.size();
        if (node->count == 0) {
            node->sons = nullptr;
            return;
        }
        node->sons = new Node * [node->count];
        for (int i = 0; i < node->count; i++) {
            node->sons[i] = new Node;
            node->sons[i]->value = value[i];
        }
        for (int i = 0; i < node->count; i+=1) {
            std::vector<char> val(value);
            std::vector<char>::iterator it;
            it = std::find(val.begin(), val.end(), node->sons[i]->value);
            if (it != val.end())
                val.erase(it);
            add(node->sons[i], val);
        }
    }
    bool isLeaf(Node* node) {
        return (node->sons == nullptr);
    }
    void treeTraversal(Node* node, std::vector<char> path) {
        if (node == nullptr) {
            return;
        }
        path.push_back(node->value);
        if (isLeaf(node)) {
            rer.push_back(path);
        }
        for (int i = 0; i < node->count; i++) {
            treeTraversal(node->sons[i], path);
        }
        path.pop_back();
    }
    void treeTraversal(Node* node) {
        std::vector<char> path;
        treeTraversal(node, path);
    }

 public:
    explicit Tree(std::vector<char> value) {
        node = new Node;
        root = node;
        node->value = '*';
        add(node, value);
    }
    void print() {
        treeTraversal(root);
    }
    std::vector<std::vector<char>> Perm() {
        return rer;
    }
};

#endif  // INCLUDE_TREE_H_
