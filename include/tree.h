// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    struct Node {
        std::vector<Node*> children;
        char value;
        explicit Node(char val) {
            value = val;
        }
        ~Node() {
            for (Node* child : children) {
                delete child;
            }
        }
    };

 public:
    explicit Tree(const std::vector<char>& sequence) {
        root = new Node(-1);
        buildTree(root, sequence);
        createPermutations(root, {});
    }
    ~Tree() {
        delete root;
    }
    std::vector<std::vector<char>> getPermutations() const {
        return permutations;
    }

 private:
    void buildTree(Node* node, const std::vector<char>& sequence) {
        if (sequence.empty()) {
            return;
        }
        for (std::size_t i = 0; i < sequence.size(); ++i) {
            std::vector<char> next_sequence = sequence;
            next_sequence.erase(next_sequence.begin() + i);
            Node* child = new Node(sequence[i]);
            node->children.push_back(child);
            buildTree(child, next_sequence);
        }
    }
    void createPermutations(Node* node, std::vector<char> elements) {
        if (node != nullptr) {
            if (node->value != -1) {
                elements.push_back(node->value);
            }
            if (node->children.empty()) {
                permutations.push_back(elements);
            }
            for (Node* child : node->children) {
                createPermutations(child, elements);
            }
        }
    }

 private:
    Node* root;
    std::vector<std::vector<char>> permutations;
};
#endif  // INCLUDE_TREE_H_
