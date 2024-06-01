// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
private:
    struct Node {
        char value;
        std::vector<Node*> potomki;

        Node(char val) : value(val) {}
    };

    Node* root;
    std::vector<std::vector<char>> vecPermutations;

    void treeBuild(Node* currentNode, const std::vector<char>& initValues) {
        for (size_t i = 0; i < initValues.size(); i++) {
            Node* child = new Node(initValues[i]);
            std::vector<char> leftValues = initValues;
            leftValues.erase(leftValues.begin() + i);
            currentNode->potomki.push_back(child);
            treeBuild(currentNode->potomki.back(), leftValues);
        }
    }

    void createPerms(Node* currentNode, const std::vector<char>& initVal) {
        if (currentNode == nullptr) {
            return;
        }

        std::vector<char> leftVal = initVal;
        leftVal.push_back(currentNode->value);

        if (currentNode->potomki.empty()) {
            vecPermutations.push_back(leftVal);
        }

        for (Node* child : currentNode->potomki) {
            createPerms(child, leftVal);
        }
    }

public:
    explicit Tree(std::vector<char> inputValues) : root(nullptr) {
        root = new Node(inputValues[0]);
        treeBuild(root, inputValues);
        createPerms(root, std::vector<char>());
    }

    std::vector<char> getPermByIndex(int i) const {
        if (i < 0 || i >= static_cast<int>(vecPermutations.size())) {
            return std::vector<char>();
        }
        return vecPermutations[i];
    }
};

#endif  // INCLUDE_TREE_H_
