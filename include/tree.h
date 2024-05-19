// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Node {
 public:
    char value;
    std::vector<Node*> children;
    explicit Node(char val) : value(val) {}
    ~Node() { for (auto child : children) delete child; }
};

class Tree {
 public:
    explicit Tree(const std::vector<char>& el) {
        if (!el.empty()) {
            root = new Node(0); // корень не содержит значения
            buildTree(el, root);
        }
    }

    ~Tree() { delete root; }

    void getAllPermutations(std::vector<std::vector<char>>& result) const {
        std::vector<char> current;
        getAllPermutationsRec(root, current, result);
    }

    std::vector<char> getPermutation(int x) const {
        std::vector<std::vector<char>> result;
        getAllPermutations(result);
        if (x >= 1 && x <= static_cast<int>(result.size())) {
            return result[x - 1];
        }
        return {}; 
    }

 private:
    Node* root = nullptr;

    
    void buildTree(const std::vector<char>& el, Node* node) {
        if (el.empty()) return;

        for (size_t i = 0; i < el.size(); ++i) {
            std::vector<char> nextElems(el.begin(), el.end());
            nextElems.erase(nextElems.begin() + i);
            Node* child = new Node(el[i]);
            node->children.push_back(child);
            buildTree(nextElems, child);
        }
    }

    
    void getAllPermutationsRec(Node* node, std::vector<char>& current, std::vector<std::vector<char>>& result) const {
        if (!node) return;

        if (node->value != 0)
            current.push_back(node->value);

        if (node->children.empty()) {
            result.push_back(current);
        } else {
            for (Node* child : node->children) {
                getAllPermutationsRec(child, current, result);
            }
        }

        if (!current.empty() && node->value != 0) // пропускаем корень без значения
            current.pop_back();
    }
};
#endif  // INCLUDE_TREE_H_
