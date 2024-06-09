// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <cstdint>
#include <string>
#include <vector>

class Tree {
 private:
    struct Node;
    std::vector<std::string> repl;
    Node* fort;

    void createTree(Node* fort, std::vector<char> trail);

    void generatePermutations(Node* fort, std::string symb);

 public:
    explicit Tree(const std::vector<char>);

    std::string operator[] (unsigned int i) const;
};
#endif  // INCLUDE_TREE_H_
