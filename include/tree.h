// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <string>
#include <vector>

class Node {
        char value;
        std::vector<Node*> children;
        explicit Node(char val) : value(val) {}

        ~Node() {
            for (auto child : children) {
                delete child;
            }
        }
    };
class Tree {

 private:
    Node* root;
    std::vector<std::vector<char>> allPermutations;

    void buildTree(Node* node, const std::vector<char>& remainingChars) {
        for (char elem : remainingChars) {
            Node* child = new Node(elem);
            node->children.push_back(child);
            std::vector<char> nextCh(remainingChars);
            nextCh.erase(std::remove(nextCh.begin(), nextCh.end(), elem), nextCh.end());
            buildTree(child, nextCh);
        }
    }

    void generatePermutations(Node* node, std::vector<char>& currentPermutation) {
        currentPermutation.push_back(node->value);

        if (node->children.empty()) { // Достигли листа
            allPermutations.push_back(currentPermutation);
        } else {
            for (auto child : node->children) {
                generatePermutations(child, currentPermutation);
            }
        }
        currentPermutation.pop_back();
    }

 public:
    explicit Tree(const std::vector<char>& inputChars) : root(new Node(' ')) {
        buildTree(root, inputChars);
        std::vector<char> currentPermutation;
        for (auto child : root->children) {
            generatePermutations(child, currentPermutation);
        }
    }

    ~Tree() {
        delete root;
    }
    friend std::vector<char> getPerm(const Tree& tree, int n);
};

std::vector<char> getPerm(const Tree& tree, int index);

#endif  // INCLUDE_TREE_H_
