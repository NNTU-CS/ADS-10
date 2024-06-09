// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Node {
private:
    char data;
    std::vector<Node*> children;
public:
    Node(char newData) : data(newData) {}

    char getData() const { return data; }
    Node* getChild(int index) const { return children[index]; }
    void addChild(Node* child) { children.push_back(child); }
    int getChildrenCount() const { return children.size(); }
};

class Tree {
private:
    Node* root;
    std::vector<std::vector<char>> permutations;

    void generatePermutations(Node* current, std::vector<char>& path) {
        path.push_back(current->getData());

        if (current->getChildrenCount() == 0) {
            permutations.push_back(path);
        } else {
            for (int i = 0; i < current->getChildrenCount(); i++) {
                generatePermutations(current->getChild(i), path);
            }
        }

        path.pop_back();
    }

public:
    Tree(const std::vector<char>& elements) {
        root = new Node('\0');

        std::vector<char> sortedElements = elements;
        std::sort(sortedElements.begin(), sortedElements.end());

        for (char elem : sortedElements) {
            root->addChild(new Node(elem));
        }
    }

    Node* getRoot() const { return root; }
    int getTotalPerms() const { return permutations.size(); }
    std::vector<char> getPerm(int n) const { return permutations[n - 1]; }

    void generateAllPermutations() {
        std::vector<char> path;
        generatePermutations(root, path);
    }
};

#endif  // INCLUDE_TREE_H_
