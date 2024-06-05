// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    struct Node {
        std::vector<Node *> perems;
        char value;
    };
    Node *root;
    std::vector<std::vector<char>> permutations;

    void buildTree(Node *node, std::vector<char> values) {
        if (!node) {
            node = new Node;
        }
        if (values.empty()) {
            return;
        }
        for (int i = 0; i < values.size(); i++) {
            std::vector<char> rValues = values;
            Node *perem = new Node;
            perem->value = values[i];
            node->perems.push_back(perem);
            rValues.erase(rValues.begin() + i);
            buildTree(node->perems.back(), rValues);
        }
    }
    void generatePermutations(Node* node, const std::vector<char>& current) {
        std::vector<char> upCurrent = current;
        for (int i = 0; i < node->perems.size(); i++) {
            upCurrent.push_back(node->perems[i]->value);
            if (node->perems[i]->perems.empty()) {
                if (current.size() != 1) {
                    permutations.push_back(upCurrent);
                }
            }
            generatePermutations(node->perems[i], upCurrent);
            upCurrent.pop_back();
        }
    }

 public:
    explicit Tree(std::vector<char> values): root(nullptr) {
        root = new Node;
        buildTree(root, values);
        std::vector<char> current;
        generatePermutations(root, current);
    }
    std::vector<char> getPermutation(int index) const {
        if (index < 0 || index >= permutations.size()) {
            return std::vector<char>();
        }
        return permutations[index];
    }
};
#endif  // INCLUDE_TREE_H_
