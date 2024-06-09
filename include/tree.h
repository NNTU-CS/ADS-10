// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    struct Node {
        std::vector<Node *> childrens;
        char value;
    };
    Node *root;
    std::vector<std::vector<char>> permutations;

    void buildTree(Node *node, std::vector<char> values) {
        if (values.empty()) {
            return;
        }
        if (!node) {
            node = new Node;
        }
        for (int k = 0; k < values.size(); k++) {
            std::vector<char> remainValues = values;
            Node *child = new Node;
            child->value = values[k];
            node->childrens.push_back(child);
            remainValues.erase(remainValues.begin() + k);
            buildTree(node->childrens.back(), remainValues);
        }
    }
    void generatePermutation(Node* node, const std::vector<char>& current) {
        std::vector<char> newCurrent = current;
        for (int k = 0; k < node->childrens.size(); k++) {
            newCurrent.push_back(node->childrens[k]->value);
            if (node->childrens[k]->childrens.empty()) {
                if (current.size() != 1) {
                    permutations.push_back(newCurrent);
                }
            }
            generatePermutation(node->childrens[k], newCurrent);
            newCurrent.pop_back();
        }
    }

 public:
    explicit Tree(std::vector<char> values): root(nullptr) {
        root = new Node;
        buildTree(root, values);
        std::vector<char> current;
        generatePermutation(root, current);
    }
    std::vector<char> getPermutation(int index) const {
        if (index >= permutations.size() || index < 0) {
            return std::vector<char>();
        }
        return permutations[index];
    }
};
#endif  // INCLUDE_TREE_H_
