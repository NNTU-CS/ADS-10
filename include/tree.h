// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class Tree {
 private:
    struct Node {
        std::vector<Node*> childrenperm;
        char x;

        Node(char val) : x(val) {}

        ~Node() {
            for (auto deti : childrenperm) {
                delete deti;
            }
        }
    };

    Node* root;
    std::vector<std::vector<char>> permutations;

    void Recursive(Node* node, const std::vector<char>& values);
    void generatePermutationsRecursive(Node* node, std::vector<char> current);

 public:
    explicit Tree(const std::vector<char>& values);
    ~Tree();

    std::vector<char> getPermutation(int index) const;
};

Tree::Tree(const std::vector<char>& values) {
    root = new Node(0);
    Recursive(root, values);
    std::vector<char> current;
    generatePermutationsRecursive(root, current);
}

Tree::~Tree() {
    delete root;
}

void Tree::Recursive(Node* node, const std::vector<char>& values) {
    if (values.empty()) {
        return;
    }

    for (size_t i = 0; i < values.size(); ++i) {
        std::vector<char> nextElems(values.begin(), values.end());
        nextElems.erase(nextElems.begin() + i);

        Node* deti = new Node(values[i]);
        node->childrenperm.push_back(deti);

        Recursive(deti, nextElems);
    }
}

void Tree::generatePermutationsRecursive(Node* node, std::vector<char> current) {
    for (int i = 0; i < node->childrenperm.size(); i++) {
        current.push_back(node->childrenperm[i]->x);
        if (node->childrenperm[i]->childrenperm.empty()) {
            permutations.push_back(current);
        }
        generatePermutationsRecursive(node->childrenperm[i], current);
        current.pop_back();
    }
}

std::vector<char> Tree::getPermutation(int index) const {
    if (index < 0 || index >= permutations.size()) {
        return std::vector<char>();
    }
    return permutations[index];
}

#endif  // INCLUDE_TREE_H_
