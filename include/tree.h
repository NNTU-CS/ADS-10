// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>
#include <iostream>

class Tree {
 private:
    struct Node {
        char data;
        std::vector<Node*> sheet;
    };
    Node* root;
    std::vector<std::string> permutation;
    void constructTree(Node* root, std::vector<char> numbers) {
        if (!numbers.size()) {
            return;
        }
        if (root->data != '*') {
            for (auto x = numbers.begin(); x != numbers.end(); ++x) {
                if (*x == root->data) {
                    numbers.erase(x);
                    break;
                }
            }
        }
        for (size_t i = 0; i < numbers.size(); ++i) {
            root->sheet.push_back(new Node);
        }
        for (size_t i = 0; i < root->sheet.size(); ++i) {
            root->sheet[i]->data = numbers[i];
        }
        for (size_t i = 0; i < root->sheet.size(); ++i) {
            constructTree(root->sheet[i], numbers);
        }
    }
    void Permutation(Node* root, std::string s = "") {
        if (!root->sheet.size()) {
            s += root->data;
            permutation.push_back(s);
            return;
        }
        if (root->data != '*') {
            s += root->data;
        }
        for (size_t i = 0; i < root->sheet.size(); ++i) {
            Permutation(root->sheet[i], s);
        }
    }

 public:
    explicit Tree(std::vector<char> v) {
        root = new Node;
        root->data = '*';
        constructTree(root, v);
        Permutation(root);
    }
    std::vector<char> getPermutation(int j) const {
        std::vector<char> numberPerm;
        if (j < 0 || j >= permutation.size()) {
            return numberPerm;
        } else {
            numberPerm.resize(permutation[j].length(), ' ');
            for (int z = 0; z < permutation[j].length(); ++z) {
                numberPerm[z] = permutation[j][z];
            }
        }
        return numberPerm;
    }
};
#endif  // INCLUDE_TREE_H_
