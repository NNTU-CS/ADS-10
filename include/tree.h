// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <cstdlib>

class Tree {
 public:
    struct Node {
        std::vector<char> values;
        std::vector<Node*> nodes;
    };

 private:
    Node* root;

    Node* create(Node* root, std::vector<char> values) {
        root = new Node{ values };
        for (int i = 0; i < values.size(); i++) {
            std::vector<char> childvalues;
            for (char value : values) {
                if (value != values[i]) {
                    childvalues.push_back(value);
                }
            }
            if (childvalues.empty()) {
                return root;
            }
            root->nodes.push_back(nullptr);
            root->nodes[i] = create(root->nodes[i], childvalues);
        }
        return root;
    }

    int depthNode(Node* root) const {
        int depth = 0;
        Node* curr = root;
        while (!curr->nodes.empty()) {
            curr = curr->nodes.front();
            depth++;
        }
        return ++depth;
    }

    int factorial(int n) const {
        if (n == 1) return n;
        return n * factorial(n - 1);
    }

    std::vector<char> getPermNode(Node* root, int n) const {
        if (root->nodes.empty()) {
            return root->values;
        }
        int depth = depthNode(root);
        auto div = std::div(n, factorial(depth) / depth);
        std::vector<char> perm = { root->values[div.quot] };
        for (char c : getPermNode(root->nodes[div.quot], div.rem)) {
            perm.push_back(c);
        }
        return perm;
    }

 public:
    explicit Tree(std::vector<char> values) {
        root = create(root, values);
    }

    std::vector<char> getPerm(int n) const {
        if (n > factorial(depthNode(root)) || n < 1) {
            return std::vector<char>();
        }
        return getPermNode(root, n - 1);
    }
};

#endif  // INCLUDE_TREE_H_
