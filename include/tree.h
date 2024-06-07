// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <cstdint>
#include <string>
#include <vector>

class Tree {
 private:
    struct Node;
    std::vector<std::string> permutations;
    Node* root;
    void buildTree(Node* node, std::vector<char> elements);
    void generatePermutations(Node* node, std::string current);
 public:
    Tree();
    Tree(const std::vector<char>& elements);
    std::string operator[](unsigned int index) const;
};
#endif  // INCLUDE_TREE_H_
