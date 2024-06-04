// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>
class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node *> children;

        explicit Node(char val) : value(val) {}

        ~Node() {
            for (auto child : children) {
                delete child;
            }
        }
    };

    Node *root;
    std::vector<std::vector<char>> permutations;

    void fillNode(Node *node, std::vector<char> values) {
        values.erase(std::remove(values.begin(),
                                 values.end(), node->value), values.end());
        for (auto value : values) {
            node->children.push_back(new Node(value));
        }
        for (auto child : node->children) {
            fillNode(child, values);
        }
    }

    void generatePermutations(Node* node, std::vector<char> permutation) {
        permutation.push_back(node->value);
        if (node->children.empty()) {
            permutations.push_back(permutation);
        } else {
            for (auto child : node->children) {
                generatePermutations(child, permutation);
            }
        }
        permutation.pop_back();
    }

 public:
    explicit Tree(const std::vector<char> &input) : root(new Node(' ')) {
        for (auto value : input) {
            Node *child = new Node(value);
            root->children.push_back(child);
            fillNode(child, input);
            std::vector<char> permutation;
            generatePermutations(child, permutation);
        }
    }

    ~Tree() {
        delete root;
    }

    friend std::vector<char> getPerm(const Tree &tree, int n);
};
#endif  // INCLUDE_TREE_H_
